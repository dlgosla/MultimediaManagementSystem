#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "SortedLinkedList.h"
#include "SortedList.h"
#include "Event.h"
#include "FC.h"
#include "People.h"
#include "Album.h"

#define FILENAMESIZE 1024

class Application {
public:
	/*
	* pre:none
	* post: 앨범과 관련된 메뉴
	*/
	void runAlbum() {
		while (1) {
			cout << "======앨범 메뉴=====" << endl;
			cout << "1. 앨범 이름 추가" << endl;
			cout << "2. 앨범 이름 삭제" << endl;
			cout << "3. 앨범에 사진 추가" << endl;
			cout << "4. 앨범에 사진 삭제" << endl;
			cout << "다른숫자: 뒤로가기" << endl;
			cout << "==================" << endl;

			int input;
			cout << ">> ";
			cin >> input;

		}
		
	}

	/*
	* pre:none
	* post: 이름을 입력받아 그 이름을 앨범명으로 가지는 앨범을 추가한다
	*/
	void addAlbum() {
		
	}

	/*
	* pre: 앨범명이 앨범리스트에 있어야 한다, 그 앨범 그룹에 추가할 컨텐츠와 중복된 컨텐츠가 없어야한다
	* post: 특정 앨범명을 입력받아 그 앨범그룹에 컨텐츠를 추가한다
	*/
	void addContentsInAlbum() {}

	/*
	* pre: 앨범명이 앨범 리스트에 있어야 한다, 그 앨범안에 해당 컨텐츠가 있어야한다
	* post: 앨범이름과 콘텐츠 이름을 키보드로 입력받아서 그 앨범안에서 해당 컨텐츠를 삭제한다
	*/
	void deleteContentsInAlbum() {}

	/*
	* pre: 앨범이 하나이상 존재해야한다
	* post: 그 이름을 앨범명으로 가지는 앨범을 삭제한다
	*/
	void deleteAlbum() {}


	/*
	* pre:none
	* post: location 리스트 안으로 한정해 탐색한다
	*/
	void searchInLocation() {

	}

	/*
	* pre:none
	* post: FC 리스트 안으로 한정해 탐색한다
	*/
	void searchInFC() {

	}

	/*
	* pre:none
	* post: PHOTO 타입 FC 리스트 안으로 한정해 탐색한다
	*/
	void searchInPhotoFC() {

	}

	/*
	* pre:none
	* post: Video타입 FC 리스트 안으로 한정해 탐색한다
	*/
	void searchInVideoFC() {

	}

	/*
	* pre:none
	* post: 사진 타입 FC를 출력한다
	*/
	void printPhotoFC() {

	}

	/*
	* pre: none
	* post:비디오 타입 FC를 출력한다
	*/
	void printVideoFC() {

	}

	/*
	* 키보드로 부터 조건을 입력받아서 특정 이벤트 객체 내에서 한정해서 검색
	* pre: 이벤트 리스트에 이벤트가 정의돼 있어야함
	* post: 특정 이벤트 이름을 입력받고 그 이벤트 그룹 내에서 검색
	*/
	void SearchInEvent() {

	}


	/*
	* 키보드로 부터 조건을 입력받아서 특정 사람 객체 내에서 한정해서 검색
	* pre: 사람 리스트에 그 사람이 정의돼 있어야함
	* post: 특정 사람의 이름을 입력받고 그 사람 그룹 내에서 검색
	*/
	void SearchInPeople() {

	}


	void runPeople()//people 메뉴
	{

	}

	/*
	* pre: people이 존재해야함
	* post: 존재하는 모든 사람과 거기 속하는 콘텐츠 출력
	*/
	void printAllPeople() {

	}

	/*
	* pre: 그 사람의 이름이 people 리스트에 있어야 함
	* post: 사용자에게 사람이름을 입력받아 하나의 people 그룹을 삭제하고 성공시 1 리턴
	*/
	int deletePeople() {

	}

	/*
	* pre: 추가할 사람 이름이 people 리스트에 없어야 함
	* post: 한 이벤트를 저장할 people 타입의 노드를 만들고 성공시 1 리턴
	*/
	int addPeople(){
	}

	/*
	* 사람 이름을 입력받아서 거기 소속된 콘텐츠의 자세한 정보를 출력
	* pre: people 리스트에 해당 people 클래스가 있어야 한다
	* post: 해당People에 소속된 콘텐츠의 자세한 정보를 출력
	*/
	void FindNDisplayPeople() {

	}


	/*
	* pre: 이벤트가 존재해야함
	* post: 존재하는 모든 이벤트와 거기 속하는 콘텐츠 출력
	*/
	void printAllEvent();

	/*
	* pre:이벤트 명이 이벤트 리스트에 있어야함
	* post: 사용자에게 이벤트명을 입력받아 하나의 이벤트 그룹을 삭제하고 성공시 1 리턴
	*/
	int deleteEvent();

	/*
	* pre:이벤트 명이 이벤트 리스트에 없어야 함
	* post: 한 이벤트를 저장할 이벤트 타입의 노드를 만들고 성공시 1 리턴
	*/
	int addEvent();

	/*
	컨텐츠를 입력받아서 마스터리스트, 이벤트리스트, FC리스트에 저장한다
	precondition: primary key가 중복되면 안된다
	postcondition: 추가하고 성공하면 1 실패하면 0을 반환한다
	*/
	int AddContents();

	/*
	* 이벤트 이름을 입력받아서 거기 소속된 콘텐츠의 자세한 정보를 출력
	* pre: 이벤트 리스트에 해당 이벤트 클래스가 있어야 한다
	* post: 해당이벤트에 소속된 콘텐츠의 자세한 정보를 출력
	*/
	void FindNDisplayEvent();

	/*
	생성자
	*/
	Application();
	/*
	* 소멸자
	*/
	~Application();

	/*
	* 기본 메뉴창
	*/
	void Run(); //메뉴

	/*
	* 기본메뉴창에서 사용자의 선택을 받음
	*/
	int GetCommand();

	/*
	* pre: 콘텐츠가 존재해야함
	* post: 존재하는 모든 콘텐츠 출력
	*/
	void DisplayAllContents();

	/*
	precondition: fileName의 파일이 존재해야한다
	postcondition: 파일을 열었으면 1 실패했으면 0을 반환
	*/
	int OpenInFile(char* fileName);

	/*
	precondition: fileName의 파일이 존재해야한다
	postcondition: 파일을 열었으면 1 실패했으면 0을 반환
	*/
	int OpenOutFile(char* fileName);

	/*
	precondition: m_InFile이 정의돼 있어야 한다. filename과 일치하는 파일이 있어야 한다
	postcondition: 파일에서 데이터를 읽고 성공하면 1 실패하면 0을 반환
	파일명을 입력받아 해당 콘텐츠의 모든 정보를 출력
	*/
	int ReadDataFromFile();

	/*
	precondition: m_OutFile이 정의돼 있어야 한다.
	postcondition: 파일에 저장하고 성공하면 1 실패하면 0을 반환
	*/
	int WriteDataToFile();

	/*
		precondition: data가 m_List안에 있어야 한다
		postcondition: m_List에서 data와 일치하는 레코드를 삭제하고 성공하면 1, 실패하면 0을 반환
	*/
	int DeleteContents();

	/*
		precondition: m_List가 정의돼 있어야 한다, m_List에 data와 primary key가 일치하는 값이 있어야 한다
		postcondition: primary key와 일치하는 레코드를 data의 값으로 대체하고 성공시 1 실패시 0을 반환
	*/
	int ReplaceContents();

	/*
	precondition: m_List가 정의돼 있어야 한다
	postcondition: 배열을 비운다
	*/
	void MakeEmpty();

	//int SearchByName();

	/*
		precondition: m_List가 정의돼 있어야 한다, m_List에 data와 primary key가 일치하는 값이 있어야 한다
		postcondition: primary key와 일치하는 레코드를 data의 값으로 대체하고 성공시 1 실패시 0을 반환
	*/
	int replaceItem();

	/*
	* pre: 딱히 없음
	* post: 찾으면 1 못찾으면 0 반환
	*/
	int SearchAllItmeByPeople(ItemType& data);

	/*
	* pre: m_List가 정의돼 있어야 한다
	* post: 일치하는 데이터를 찾고 성공하면 1 실패하면 0을 리턴
	*/
	int SearchByName_SequenS();

	/*
	* pre: 딱히 없음
	* post: 입력된 이름이 포함된 콘텐츠를 모두 찾고 성공 1 실패 0 반환
	*/
	int SearchByPeople(); //사람으로 찾음

	/*
	* pre: m_List가 정의돼 있어야 한다
	* post: 일치하는 데이터를 찾고 성공하면 1 실패하면 0을 리턴
	*/
	int SearchByName_BinaryS(); //컨텐츠이름을 키로해서 이진검색으로 찾음

	/*
	* pre: m_List가 정의돼 있어야 한다. 이미 FC리스트에 저장돼 있는 컨텐츠를 입력하면 안된다.
	*	전체 컨텐츠 목록중에 해당 컨텐츠가 있어야한다.
	* post: 일치하는 데이터를 찾고 성공하면 1 실패하면 0을 리턴
	*/
	int Add_FC();

	/*
	* pre: 입력된 FC가 FC리스트에 있어야 한다
	* post: 일치하는 데이터를 삭제한다
	*/
	void Delete_FC_list(); //입력된 FC를 FC_list에서 삭제

	/*
	* pre: fc리스트가 정의돼 있어야한다
	* post: fc_list의 정보를 화면에 출력한다
	*/
	void Display_FC_list(); //FC_list에 들어있는 정보를 화면에 출력

	/*
	* pre: fc리스트가 정의돼 있어야한다
	* post: fc_list의 자세한 정보를 화면에 출력한다
	*/
	void Display_Detail_FC();// 특정 FC의 자세한 정보(master list에 저장된 정보)를 화면에 출력

	/*
	* pre: fc리스트가 정의돼 있어야한다
	* post: fc_list의 자세한 정보를 화면에 출력한다
	*/
	void Rearrange_FC(); //키보드로부터 조건을 입력받아서 FC의 보는 순서(들어온 순, 이름 순, 자주보는 순, 등)를 바꾼다.

	/*
	* fc 관련 메뉴창
	*/
	void runFC(); //FC 관련 메뉴 
	void run1(); //처음 뜰 메뉴
	void runEvent(); //이벤트 관련 메뉴

	//void FindNDisplayEvent(); //이벤트 이름을 입력받아서 거기 소속된 콘텐츠의 자세한 정보를 출력


private:
	ifstream m_InFile;///< input file descriptor. 
	ofstream m_OutFile;///< output file descriptor.
	SortedList<ItemType> m_List;///< item list. 마스터리스트
	int m_Command;///< current command number

	SortedLinkedList<Event> eventList; //각 이벤트 마다 리스트로 저장
	SortedList<FC> fc_list; // 순차적으로 저장되는 
	UnsortedList<FC> unsortedFC; //들어온 순서대로 저장되는 

	SortedList<FC> fc_photo; //사진별 fc리스트
	SortedList<FC> fc_video; //동영상별 fc리스트
	UnsortedList<People> peopleList; //사람별 리스트
	UnsortedList<Album> albumList; //앨범 리스트




};
