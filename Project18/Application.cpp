
#include "Application.h"

int Application::ReplaceFile()
{
	ReadDataFromFile();
	ReplaceContents();
	WriteDataToFile();
	return 1;
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
	return m_List.Delete(data);
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
	return m_List.Replace(data);
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
			ReplaceFile();
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
int Application::AddContents()
{
	/*
	precondition: primary key가 중복되면 안된다
	postcondition: 추가하고 성공하면 1 실패하면 0을 반환한다
	*/
	if (m_List.IsFull())
	{
		cout << "꽉 찼습니다" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB();
	m_List.Add(item);

	DisplayAllContents();

	return 1;
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