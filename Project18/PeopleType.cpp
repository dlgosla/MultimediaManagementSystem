#include "PeopleType.h"

PeopleType::PeopleType()
{
	contentsName = ""; //콘텐츠 파일명
	people = ""; //사람이름
}
PeopleType::~PeopleType() {}


/*
precondition: name이 정의돼 있어야 한다
postcondition: name을 리턴한다
*/
string PeopleType::GetContentsName()
{
	return contentsName;
}

/*
precondition:  people가 정의돼 있어야 한다
postcondition:  people를 리턴한다
*/
string PeopleType::GetPeople()
{
	return people;
}

/*
precondition:  name이 정의돼 있어야 한다
postcondition: name을 입력받은 값으로 바꾼다
*/
void PeopleType::SetContentsName(string inputName)
{
	contentsName = inputName;
}

/*
precondition: people가 정의돼 있어야 한다
postcondition: people를 입력받은 값으로 바꾼다
*/
void PeopleType::SetPeople(string inputPeople)
{
	people = inputPeople;
}

/*
precondition: name, kindOfContents, date, peoplem people가 정의 돼 있어야 한다
postcondition: 각 변수를 입력받은 값으로 바꾼다
*/
void PeopleType::SetRecord(string Name, string people)
{
	contentsName = Name;
	this->people = people;
}


/*
precondition: name, kindOfContents, date, peoplem people, classification, memo가 정의돼 있어야한다
postcondition: 각 요소의 자세한 정보를 출력한다
*/
void PeopleType::DisplayRecordOnScreen(SortedList<ItemType>& master)
{
	master.ResetList();
	ItemType item;
	item.SetName(contentsName);
	master.Retrieve_SeqS(item);
	item.DisplayRecordOnScreen();
}

/*
precondition: name, kindOfContents, date, peoplem people, classification, memo가 정의돼 있어야한다
postcondition: 각 요소를 출력한다
*/
void PeopleType::DisplayRecordOnScreen()
{
	cout << "사람명: " << people << "컨텐츠 이름: " << contentsName << endl;
}

/*
precondition: name이 정의돼 있어야한다
postcondition: name을 입력받는다
*/
void PeopleType::SetContentsNameFromKB()
{
	cout << "콘텐츠 파일명을 입력해주세요: ";
	cin >> contentsName;
}

/*
precondition: people가 정의돼 있어야한다
postcondition: people를 입력받는다
*/
void PeopleType::SetPeopleFromKB()
{
	cout << "사람이름 입력해주세요: ";
	cin >> people;
}

/*
precondition: 본문의 함수들이 정의돼 있어야한다
postcondition: 함수들을 호출한다
*/
void PeopleType::SetRecordFromKB()
{
	SetContentsNameFromKB();
	SetPeopleFromKB();
}

/*
precondition: data의 name과 name이 일치하는 것이 있어야 한다
postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
*/
RelationType PeopleType::CompareByName(const PeopleType& data)// primary key (ID)를기준으로콘텐츠정보를비교하는함수
{
	if (data.contentsName > contentsName)
		return LESS;

	else if (data.contentsName < contentsName)
		return GREATER;
	else
		return EQUAL;
}