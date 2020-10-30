#include "Application.h"
#include "ItemType.h"
#include "SortedList.h"

void Application::printAllEvent()
{
	/*
	* pre: 이벤트가 존재해야함
	* post: 존재하는 모든 이벤트와 거기 속하는 콘텐츠 출력
	*/
	eventList.ResetList();
	Event e;
	for (int i = 0; i < eventList.GetLength(); i++)
	{

		eventList.GetNextItem(e);
		cout << "=======이벤트 " << e.getEventName() << "속 컨텐츠========" << endl;
		e.printRecord(m_List);
		cout << "=========================================" << endl;
	}

}


int Application::deleteEvent()
{
	/*
	* pre:이벤트 명이 이벤트 리스트에 없어야 함
	* post: 사용자에게 이벤트명을 입력받아 하나의 이벤트 그룹을 삭제하고 성공시 1 리턴
	*/
	string eName;
	Event e;

	cout << "이벤트 명: ";
	cin >> eName;

	e.setRecord(eName);
	eventList.Delete(e);

	return 1;
}

int Application::addEvent()
{
	/*
	* pre:이벤트 명이 이벤트 리스트에 없어야 함
	* post: 한 이벤트를 저장할 이벤트 타입의 노드를 만들고 성공시 1 리턴
	*/
	string eName;
	Event e;

	cout << "이벤트 명: ";
	cin >> eName;

	e.setRecord(eName);
	eventList.Add(e);

	return 1;

}
int Application::AddContents()
{
	/*
	컨텐츠를 입력받아서 마스터리스트, 이벤트리스트, FC리스트에 저장한다
	precondition: primary key가 중복되면 안된다
	postcondition: 추가하고 성공하면 1 실패하면 0을 반환한다
	*/
	if (m_List.IsFull())
	{
		cout << "꽉 찼습니다" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB(); //컨텐츠를 입력받아서
	int result = m_List.Add(item);  //마스터 리스트에 컨텐츠를 추가
	if (result == 0)
		return 0;

	//이벤트 리스트에 컨텐츠 추가
	EventType eItem;
	Event e;
	eItem.SetRecord(item.GetName(), item.GetEvent()); //이벤트 타입에 컨텐츠 정보 추가
	e.setRecord(item.GetEvent()); //이벤트에 컨텐츠 정보 추가

	eventList.Add(e); //이벤트 리스트에 이벤트 추가

	eventList.Get(e);
	e.Add(eItem);
	eventList.Replace(e); //이벤트 리스트 안의 이벤트의 컨텐츠 추가


	//fc 리스트에 추가
	string user;

	while (true)
	{
		cout << "즐겨찾기로 추가하시겠습니까?(yes/no)" << endl;
		cin >> user;

		if (user == "yes")
		{
			FC temp;
			temp.setRecord(item.GetName());
			fc_list.Add(temp);
			break;
		}

		else if (user == "no")
		{
			cout << "추가하지 않습니다" << endl;
			break;
		}
		else
		{
			cout << "잘못된 입력입니다" << endl;
		}
	}
	DisplayAllContents();
	return 1;
}


void Application::FindNDisplayEvent() //이벤트 이름을 입력받아서 거기 소속된 콘텐츠의 자세한 정보를 출력
{
	string eName;
	cout << "컨텐츠 정보를 볼 이벤트 명을 입력하세요: ";
	cin >> eName;

	Event temp;
	temp.setRecord(eName);
	eventList.Get(temp);
	cout << "========이벤트 " << eName << "속 컨텐츠========" << endl;
	temp.printRecord(m_List);
	cout << "============================" << endl;
}

Application::Application()
{
	m_Command = 0;
}
Application::~Application() {}

int Application::Add_FC() //콘텐츠를 선정하여 FC_list에 추가
{
	/*
	* pre: m_List가 정의돼 있어야 한다. 이미 FC리스트에 저장돼 있는 컨텐츠를 입력하면 안된다.
	*	전체 컨텐츠 목록중에 해당 컨텐츠가 있어야한다.
	* post: 일치하는 데이터를 찾고 성공하면 1 실패하면 0을 리턴
	*/
	ItemType item;

	item.SetNameFromKB();	//name를 입력받는다
	if (m_List.Retrieve_BinaryS(item))	//이진탐색에 성공했다면
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		FC temp;
		int count;
		cout << "이 콘텐츠를 본 횟수: ";
		cin >> count;
		temp.setRecord(item.GetName(), count);
		fc_list.Add(temp);
		unsortedFC.Add(temp);
		cout << "<============I 저장완료 !==========>" << endl;
		return 1;
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;
}

void Application::Delete_FC_list() //입력된 FC를 FC_list에서 삭제
{
	string name;
	cout << "삭제할 FC의 이름: ";
	cin >> name;
	FC temp;
	temp.setRecord(name);
	fc_list.Delete(temp);
	unsortedFC.Delete(temp);
}

void Application::Display_FC_list() //FC_list에 들어있는 정보를 화면에 출력
{
	fc_list.DisplayRecord();
}


void Application::Display_Detail_FC()// 특정 FC의 자세한 정보(master list에 저장된 정보)를 화면에 출력
{
	string name;
	cout << "FC의 자세한 정보를 출력하는 함수입니다 ";
	SearchByName_BinaryS();
}

void Application::runFC()
{
	while (1) {
		cout << "=======================" << endl;
		cout << "1. Add_FC " << endl;
		cout << "2. Delete_FC: " << endl;
		cout << "3.Display_FC_list" << endl;
		cout << "4. Display_Detail_FC: " << endl;
		cout << "5. Rearrange_FC" << endl;
		cout << "이외의 숫자: exit" << endl;

		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 1:
			Add_FC();
			break;
		case 2:
			Delete_FC_list();
			break;
		case 3:
			Display_FC_list();
			break;
		case 4:
			Display_Detail_FC();
			break;
		case 5:
			Rearrange_FC();
		default:
			return;
			break;
		}
	}
}

void Application::run1()
{

	while (1) {
		cout << "=======================" << endl;
		cout << "1. 기본 메뉴" << endl;
		cout << "2. FC 메뉴" << endl;
		cout << "3. 이벤트 메뉴" << endl;
		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 1:
			Run();
			break;
		case 2:
			runFC();
			break;
		case 3:
			runEvent();
			break;
		default:
			return;
		}
	}
}


void Application::runEvent() {
	while (1) {
		cout << "=======================" << endl;
		cout << "1. 이벤트 추가" << endl;
		cout << "2. 이벤트 삭제" << endl;
		cout << "3.	전체 이벤트 목록 보기" << endl;
		cout << "4.	특정 이벤트 속 컨텐츠들 보기" << endl;
		cout << "이외의 숫자:exit" << endl;
		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;

		switch(command)
		{
		case 1:
			addEvent();			
			break;
		case 2:
			deleteEvent();
			break;
		case 3:
			printAllEvent();
			break;
		case 4:
			FindNDisplayEvent();
			break;
		default:
			return;
			break;
		}
	}
}


void Application::Rearrange_FC() //키보드로부터 조건을 입력받아서 FC의 보는 순서(들어온 순, 이름 순, 자주보는 순, 등)를 바꾼다.
{

	while (1) {
		cout << "보는 순서를 입력하세요: " << endl;
		cout << "1. 이름순" << endl;
		cout << "2. 들어온 순" << endl;
		cout << "3. 자주보는 순" << endl;
		int command;
		cout << ">>";
		cin >> command;

		switch (command)
		{
		case 1:
			cout << "이름 순 " << endl;
			fc_list.DisplayRecord();
			break;

		case 2:
			cout << " 들어온 순" << endl;
			unsortedFC.DisplayRecord();
			break;
		case 3:
			cout << "자주보는 순 " << endl;
			unsortedFC.DisplayRecord();
			break;
		default:
			return;
		}
	}
}

int Application::SearchByName_BinaryS()
{
	/*
	* pre: m_List가 정의돼 있어야 한다
	* post: 일치하는 데이터를 찾고 성공하면 1 실패하면 0을 리턴
	*/
	ItemType item;

	item.SetNameFromKB();	//name를 입력받는다
	if (m_List.Retrieve_BinaryS(item))	//이진탐색에 성공했다면
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환

}

int Application::SearchByName_SequenS()
{
	/*
	* pre: m_List가 정의돼 있어야 한다
	* post: 일치하는 데이터를 찾고 성공하면 1 실패하면 0을 리턴
	*/
	ItemType data;
	data.SetNameFromKB(); 

	if (m_List.Retrieve_SeqS(data))
	{
		data.DisplayRecordOnScreen(); 
		return 1;
	}
	cout << "없습니다" << endl;
	return 0;
}

int Application::SearchAllItmeByPeople(ItemType& data)
{
	/*
	* pre: 딱히 없음
	* post: 찾으면 1 못찾으면 0 반환
	*/
	ItemType tmp;
	int result = 0;

	m_List.ResetList();//iterator 초기화
	while (m_List.GetNextItem(tmp) != -1) //리스트의 마지막까지 반복
	{
		if (tmp.GetPeople().find(data.GetPeople()) != -1) //만약 해당 리스트의 이름에 inData의 이름이 존재하면
		{
			if (result == 0) //처음 찾는 경우라면
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//성공(1)
		}
	}
	if (result)	//발견한 경우
		cout << "<====================================>" << endl;
	else	//발견 못하는 경우
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

int Application::SearchByPeople()
{
	/*
	* pre: 딱히 없음
	* post: 입력된 이름이 포함된 콘텐츠를 모두 찾고 성공 1 실패 0 반환
	*/
	ItemType item;
	item.SetPeopleFromKB(); //people을 입력받는다.

	if (SearchAllItmeByPeople(item)) //0이 아니면(찾으면)
		return 1;	//성공(1)을 리턴
	return 0;	//실패(0)을 리턴
}

int Application::replaceItem()
{
	ItemType item;
	item.SetRecordFromKB();

	m_List.Replace(item);
	cout << "=======================";
	DisplayAllContents();
	cout << "=======================";
	return 0;
}


int Application::DeleteContents()
{
	/*
		precondition: data가 m_List안에 있어야 한다
		postcondition: m_List에서 data와 일치하는 레코드를 삭제하고 성공하면 1, 실패하면 0을 반환
	*/
	ItemType data;
	data.SetNameFromKB();
	m_List.Retrieve_SeqS(data);

	EventType eItem;
	eItem.SetName(data.GetName());

	// 이벤트리스트에서 삭제
	Event e;
	e.setRecord(data.GetEvent());
	eventList.Get(e);
	e.Delete(eItem);
	eventList.Replace(e);

	if (e.getCountOfEvent() == 0)
	{
		eventList.Delete(e);
	}

	int result = m_List.Delete(data); //마스터리스트에서 삭제

	//fc리스트에서 삭제
	FC temp;
	temp.setRecord(data.GetName());
	fc_list.Delete(temp);

	return result;
}
int Application::ReplaceContents()
{
	/*
		precondition: m_List가 정의돼 있어야 한다, m_List에 data와 primary key가 일치하는 값이 있어야 한다
		postcondition: primary key와 일치하는 레코드를 data의 값으로 대체하고 성공시 1 실패시 0을 반환
	*/
	ItemType data;
	data.SetRecordFromKB();
	cout << "=======================" << endl;
	int result = m_List.Replace(data); //마스터리스트 대체

	return result;

	/*
	//이벤트 리스트 대체
	Event eTemp;
	eTemp.setRecord(data.GetName());
	eventList.Get(eTemp);
	EventType eItem;
	eItem.SetName(data.GetName());
	eTemp.replace(eItem);

	//FC리스트 대체
	FC fcTemp;
	fcTemp.setRecord(data.GetName());
	fc_list.Replace(fcTemp);
	*/
	
}

void Application::MakeEmpty()
{
	/*
	precondition: m_List가 정의돼 있어야 한다
	postcondition: 배열을 비운다
	*/
	m_List.MakeEmpty();
}
void Application::Run()
{
	/*
		precondition: 케이스에 해당하는 함수가 전부 저장돼있어야한다
		postcondition: 함수를 실행시킨다
	*/
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddContents();
			break;
		case 2:		//delete
			DeleteContents();
			break;
		case 3:		//replace
			ReplaceContents();
			break;
		case 4:		//search by name.
			SearchByName_SequenS();
			break;
		case 5:	//search by binary search.
			SearchByName_BinaryS();
			break;
		case 6:		//search by people.
			SearchByPeople();
			break;
		case 7:		// display all the records in list on screen.
			DisplayAllContents();
			break;
		case 8:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 11:
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}

}
int Application::GetCommand()
{
	/*
	precondition: 딱히 없다
	postcondition: 메뉴를 보여준다
	*/
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 콘텐츠 추가" << endl;
	cout << "\t   2 : 콘텐츠 삭제" << endl;
	cout << "\t   3 : 콘텐츠 파일명을 입력받아 새 정보로 치환 (replace)" << endl;
	cout << "\t   4 : 콘텐츠 파일명으로 콘텐츠 찾아 정보 출력" << endl;
	cout << "\t   5 : 콘텐츠 파일명으로 콘텐츠 찾아 정보 출력(이진탐색)" << endl;
	cout << "\t   6 : 특정 인물이 포함된 콘텐츠 찾기" << endl;
	cout << "\t   7 : 모든 콘텐츠 정보 출력" << endl;
	cout << "\t   8 : 빈 리스트로 만들기" << endl;
	cout << "\t   9 : 파일로 부터 읽어오기" << endl;
	cout << "\t   10 : 파일에 쓰기" << endl;
	cout << "\t   11 : 텍스트 파일의 내용을 새 정보로 바꾸기" << endl; 
	//파일명을 입력받아 해당 콘텐츠의 정보를 키보드로 부터 입력받은 새 정보로 치환
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::DisplayAllContents()
{
	/*
	precondition: m_List가 정의돼 있어야한다
	postcondition: m_List의 레코드들을 전부 보여준다
	*/
	ItemType data;
	int len = m_List.GetLength();
	m_List.ResetList();
	for (int i = 0; i < len; i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
}
int Application::OpenInFile(char* fileName)
{
	/*
	precondition: fileName의 파일이 존재해야한다
	postcondition: 파일을 열었으면 1 실패했으면 0을 반환
	*/
	m_InFile.open(fileName);

	if (!m_InFile)	return 0;
	else	return 1;
}
int Application::OpenOutFile(char* fileName)
{
	/*
	precondition: fileName의 파일이 존재해야한다
	postcondition: 파일을 열었으면 1 실패했으면 0을 반환
	*/
	m_OutFile.open(fileName);
	if (!m_OutFile) return 0;
	return 1;
}
int Application::ReadDataFromFile()
{
	/*
	precondition: m_InFile이 정의돼 있어야 한다. filename과 일치하는 파일이 있어야 한다
	postcondition: 파일에서 데이터를 읽고 성공하면 1 실패하면 0을 반환
	파일명을 입력받아 해당 콘텐츠의 모든 정보를 출력
	*/
	int index = 0;
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_InFile.eof()) {
		data.ReadDataFromFile(m_InFile);
		if (m_InFile.eof()) break;
		m_List.Add(data);
	}

	m_InFile.close();

	cout << "===================" << endl;
	DisplayAllContents();
	cout << "===========================" << endl;

	return 1;
}
int Application::WriteDataToFile()
{
	/*
	precondition: m_OutFile이 정의돼 있어야 한다.
	postcondition: 파일에 저장하고 성공하면 1 실패하면 0을 반환
	*/
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;


	m_List.ResetList();

	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	
	m_OutFile.close();

	return 1;
}