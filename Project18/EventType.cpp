#include "EventType.h"

string EventType::GetName()
{
	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	return name;
}

string EventType::GetEvent()
{

	/*
	precondition:  event가 정의돼 있어야 한다
	postcondition:  event를 리턴한다
	*/
	return event;
}

void EventType::SetName(string inputName)
{
	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	name = inputName;
}

void EventType::SetEvent(string inputEvent)
{
	/*
	precondition: event가 정의돼 있어야 한다
	postcondition: event를 입력받은 값으로 바꾼다
	*/
	event = inputEvent;
}

void EventType::SetRecord(string inputName, string inputEvent)
{
	/*
	precondition: name, kindOfContents, date, peoplem event가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	name = inputName;
	event = inputEvent;
}

void EventType::DisplayNameOnScreen()
{
	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 출력한다
	*/
	cout << "콘텐츠 파일명: " << name << endl;
}

void EventType::DisplayEventOnScreen()
{
	/*
	precondition: event가 정의돼 있어야한다
	postcondition:  event를 출력한다
	*/
	cout << "이벤트명: " << event << endl;
}

void EventType::DisplayRecordOnScreen(BinarySearchTree<ItemType>& master)
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다
	*/
	//master.ResetList();
	ItemType item;
	item.SetName(name);
	bool found = false;
	master.RetrieveItem(item,found);
	item.DisplayRecordOnScreen();
}

void EventType::DisplayRecordOnScreen()
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다
	*/

	cout << "이벤트 명: " << event << "컨텐츠 이름: " << name << endl;
}

void EventType::SetNameFromKB()
{
	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 입력받는다
	*/
	cout << "콘텐츠 파일명을 입력해주세요: ";
	cin >> name;
}

void EventType::SetEventFromKB()
{	/*
	precondition: event가 정의돼 있어야한다
	postcondition: event를 입력받는다
	*/
	cout << "이벤트명을 입력해주세요: ";
	cin >> event;
}


void EventType::SetRecordFromKB()
{	/*
	precondition: 본문의 함수들이 정의돼 있어야한다
	postcondition: 함수들을 호출한다
	*/
	SetNameFromKB();
	SetEventFromKB();
}
int EventType::ReadDataFromFile(ifstream& fin)
{
	/*
	precondition: fin이 정의돼 있어야한다
	postcondition: 파일에서 읽어오고 성공하면 1을 리턴한다
	*/
	fin >> name >> event;

	return 1;
}
int EventType::WriteDataToFile(ofstream& fout)
{
	/*
	precondition: fout이 정의돼 있어야 한다
	postcondition: 각 변수들을 파일에 저장하고 성공하면 1을 리턴한다
	*/
	fout << name << " " << " " << event << endl;

	return 1;
}

RelationType EventType::CompareByName(const EventType& data)
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