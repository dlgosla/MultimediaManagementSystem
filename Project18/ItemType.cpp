#include "ItemType.h"


string ItemType::GetName()
{
	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	return name;
}
int ItemType::GetkindOfContents()
{
	/*
	precondition: kindOfContents가 정의돼 있어야 한다
	postcondition: kindOfContents를 리턴한다
	*/
	return kindOfContents;
}
string ItemType::GetDate()
{

	/*
	precondition: date가 정의돼 있어야 한다
	postcondition: date를 리턴한다
	*/
	return date;
}
string ItemType::GetPeople()
{

	/*
	precondition: people이 정의돼 있어야 한다
	postcondition: people을 리턴한다
	*/
	return people;
}
string ItemType::GetEvent()
{

	/*
	precondition:  event가 정의돼 있어야 한다
	postcondition:  event를 리턴한다
	*/
	return event;
}

void ItemType::SetName(string inputName)
{
	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	name = inputName;
}
void ItemType::SetkindOfContents(int inputKindOfContents)
{
	/*
	precondition: kindOfContents가 정의돼 있어야 한다
	postcondition: kindOfContents를 입력받은 값으로 바꾼다
	*/
	kindOfContents = inputKindOfContents;
}
void ItemType::SetDate(string inputDate)
{
	/*
	precondition: date가 정의돼 있어야 한다
	postcondition: date를 입력받은 값으로 바꾼다
	*/
	date = inputDate;
}
void ItemType::SetPeople(string inputPeople)
{
	/*
	precondition:  people이 정의돼 있어야 한다
	postcondition: people을 입력받은 값으로 바꾼다
	*/
	people = inputPeople;
}
void ItemType::SetEvent(string inputEvent)
{
	/*
	precondition: event가 정의돼 있어야 한다
	postcondition: event를 입력받은 값으로 바꾼다
	*/
	event = inputEvent;
}

int ItemType::GetClassification()
{
	/*
	precondition:  classification가 정의돼 있어야 한다
	postcondition:  classification를 리턴한다
	*/
	return classification;
}
string ItemType::GetMemo()
{
	/*
	precondition:  memo가 정의돼 있어야 한다
	postcondition:  memo를 리턴한다
	*/
	return memo;
}
void ItemType::SetClassification(int inputClassification)
{
	/*
	precondition: classification가 정의돼 있어야 한다
	postcondition: classification를 입력받은 값으로 바꾼다
	*/
	classification = inputClassification;
}
void ItemType::setMemo(string inputMemo)
{
	/*
	precondition: memo가 정의돼 있어야 한다
	postcondition: memo를 입력받은 값으로 바꾼다
	*/
	memo = inputMemo;
}

void ItemType::SetRecord(string inputName, int inputKindOfContents, string inputDate, string inputPeople, string inputEvent, int  inputClassification, string inputMeno)
{
	/*
	precondition: name, kindOfContents, date, peoplem event가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	name = inputName;
	kindOfContents = inputKindOfContents;
	date = inputDate;
	people = inputPeople;
	event = inputEvent;
	classification = inputClassification;
	memo = inputMeno;
}

void ItemType::DisplayNameOnScreen()
{
	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 출력한다
	*/
	cout << "콘텐츠 파일명: " << name << endl;
}
void ItemType::DisplayKindOnScreen()
{
	/*
	precondition: kindOfContents가 정의돼 있어야한다
	postcondition: kindOfContents를 출력한다
	*/
	cout << "콘텐츠 종류: " << kindOfContents << endl;
}
void ItemType::DisplayDateOnScreen()
{
	/*
	precondition: date가 정의돼 있어야한다
	postcondition: date를 출력한다
	*/
	cout << "생성날짜와 시간: " << date << endl;
}

void ItemType::DisplayPeopleOnScreen()
{
	/*
	precondition: people이 정의돼 있어야한다
	postcondition: people을 출력한다
	*/
	cout << "콘텐츠에 포함된 사람: " << people << endl;
}
void ItemType::DisplayEventOnScreen()
{
	/*
	precondition: event가 정의돼 있어야한다
	postcondition:  event를 출력한다
	*/
	cout << "이벤트명: " << event << endl;
}
void ItemType::DisplayClassificationOnScreen()
{
	/*
	precondition: classification가 정의돼 있어야한다
	postcondition:  classification를 출력한다
	*/
}
void ItemType::DisplayMemoOnScreen()
{
	/*
	precondition: memo가 정의돼 있어야한다
	postcondition:  memo를 출력한다
	*/
}

void ItemType::DisplayRecordOnScreen()
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다
	*/
	cout << "콘텐츠 파일명: " << name << " 콘텐츠 종류: " << kindOfContents
		<< " 생성날짜와 시간: " << date << " 콘텐츠에 포함된 사람: " << people
		<< " 이벤트명: " << event << " 콘텐츠 구분: "<< classification 
		<<" 콘텐츠 내용: "<< memo <<endl;
}
void ItemType::SetNameFromKB()
{
	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 입력받는다
	*/
	cout << "콘텐츠 파일명을 입력해주세요: ";
	cin >> name;
}

void ItemType::SetKindFromKB()
{
	/*
	precondition: kindOfContents가 정의돼 있어야한다
	postcondition: kindOfContents를 입력받는다
	*/
	cout << "콘텐츠 종류를 입력해주세요: ";
	cin >> kindOfContents;
}
void ItemType::SetDateFromKB()
{
	/*
	precondition: date가 정의돼 있어야한다
	postcondition: date를 입력받는다
	*/
	cout << "생성날짜와 시간을 입력해주세요: ";
	cin >> date;
}
void ItemType::SetPeopleFromKB()
{
	/*
	precondition: people이 정의돼 있어야한다
	postcondition: people을 입력받는다
	*/
	cout << "콘텐츠에 포함된 사람을 입력해주세요: ";
	cin >> people;
}
void ItemType::SetEventFromKB()
{	/*
	precondition: event가 정의돼 있어야한다
	postcondition: event를 입력받는다
	*/
	cout << "이벤트명을 입력해주세요: ";
	cin >> event;
}


void ItemType::SetClassificationFromKB()
{
	/*
	precondition: classification가 정의돼 있어야한다
	postcondition: classification를 입력받는다
	*/
	cout << "콘텐츠 구분을 입력해주세요: ";
	cin >> classification;
}
void ItemType::SetMemoFromKB()
{
	/*
	precondition: memo가 정의돼 있어야한다
	postcondition: memo를 입력받는다
	*/
	cout << "콘텐츠 내용을 입력해주세요: ";
	cin >> memo;
}

void ItemType::SetRecordFromKB()
{	/*
	precondition: 본문의 함수들이 정의돼 있어야한다
	postcondition: 함수들을 호출한다
	*/
	SetNameFromKB();
	SetKindFromKB();
	SetDateFromKB();
	SetPeopleFromKB();
	SetEventFromKB();
	SetClassificationFromKB();
	SetMemoFromKB();
}
int ItemType::ReadDataFromFile(ifstream& fin)
{
	/*
	precondition: fin이 정의돼 있어야한다
	postcondition: 파일에서 읽어오고 성공하면 1을 리턴한다
	*/
	fin >> name >> kindOfContents >> date >> people >> event >> classification >> memo;

	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout)
{
	/*
	precondition: fout이 정의돼 있어야 한다
	postcondition: 각 변수들을 파일에 저장하고 성공하면 1을 리턴한다
	*/
	fout << name << " " << kindOfContents << " " << date << " " << people << " " << event << " " << classification << " " << memo << endl;

	return 1;
}
RelationType ItemType::CompareByName(const ItemType& data)
{
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	if (data.name > name)
		return LESS;

	else if (data.name < name)
		return GREATER;
	else
		return EQUAL;

}