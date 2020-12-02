#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "SortedLinkedList.h"
#include "SortedList.h"
#include "Event.h"
#include "FC.h"
#include "Album.h"
#include "People.h"
#include "BinarySearchTree.h"

#define FILENAMESIZE 1024

class Application {
public:

	/*
	* pre: fc_pic리스트가 정의돼 있어야한다
	* post: fc_picList의 자세한 컨텐츠 정보를 화면에 출력한다
	*/
	void Display_Detail_Pic_FC();

	/*
	* pre: fc_vdeio리스트가 정의돼 있어야한다
	* post: fc_videoList의 자세한 컨텐츠 정보를 화면에 출력한다
	*/
	void Display_Detail_Video_FC();

	/*
	* 키보드로 부터 조건을 입력받아서 특정 사람 객체 내에서 한정해서 검색
	* pre: 사람리스트와 이벤트 리스트가 정의돼 있어야함
	* post: 사람과 이벤트 이름을 입력받고 둘 다 만족시키는 값을 찾음
	*/
	void searchPeopleInEvent();

	/*
	* 키보드로 부터 조건을 입력받아서 특정 사람 객체 내에서 한정해서 검색
	* pre: 사람리스트와 이벤트 리스트가 정의돼 있어야함
	* post: 사람과 이벤트 이름을 입력받고 사람 리스트 안에서 입력된 이벤트 값을 찾음
	*/
	void searchEventInPeople();

	/*
	* ppst: peo 관련 메뉴
	*/
	void runPeople();

	/*
	* pre: 추가할 사람 이름이 people 리스트에 없어야 함
	* post: 사람객체 내의 컨텐츠 리스트에 컨텐츠를 추가함
	*/
	void addPeople(string pName, string contentsName);
	/*
	* pre: 사람 리스트가 존재해야함
	* post: 존재하는 모든 사람객체와 그에 속하는 컨텐츠 출력
	*/
	void printAllGroup();

	/*
	* pre: 사람 리스트가 존재해야함
	* post: 특정 사람이 포함된 컨텐츠들을 출력하고 사람객체를 반환
	*/
	People printPeople();

	/*
	* post:앨범과 관련된 메뉴
	*/
	void runAlbum();
	/*
	* pre: 삭제하고자 하는 게 컨텐츠 리스트에 있어야함
	* post: 앨범에서 컨텐츠를 삭제함
	*/
	void deleteContentsInAlbum();

	/*
	* post: 추가하고자 하는 게 컨텐츠 리스트에 없어야함
	* post; 앨범에 컨텐츠를 추가함
	*/
	void addContentsInAlbum();

	/*
	* pre: 앨범 리스트가 있어야함 똑같은 앨범명이 있으면 안됨
	* post; 앨범을 추가한다.
	*/
	void addAlbum();

	/*
	* pre: 앨범 리스트가 있어야함 똑같은 앨범명이 있어햐함
	* post; 앨범을 삭제한다
	*/
	int deleteAlbum();

	/*
	* pre: 앨범 리스트가 있어야함
	* post; 모든 앨범과 앨범 내 컨텐츠를 출력
	*/
	void printAllAlbum();


	/*
	* pre: 이벤트가 존재해야함
	* post: 존재하는 모든 이벤트와 거기 속하는 콘텐츠 출력
	*/
	void printAllEvent();

	/*
	* pre:이벤트 명이 이벤트 리스트에 없어야 함
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
	Event FindNDisplayEvent();

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
	* pre: 이벤트가 존재해야함
	* post: 존재하는 모든 이벤트와 거기 속하는 콘텐츠 출력
	*/
	void DisplayAllContents();
	int DeleteContents();
	void MakeEmpty();

	//int SearchByName();

	int SearchByName_SequenS();

	int SearchByPeople(); //사람으로 찾음
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
	BinarySearchTree<ItemType> m_List;///< item list. 마스터리스트
	int m_Command;///< current command number

	
	SortedLinkedList<Event> eventList; //각 이벤트 마다 리스트로 저장
	SortedList<FC> fc_videoList; // video fc만 따로 저장하는 리스트
	SortedList<FC> fc_picList; //사진 fc만따로 저장하는 리스트
	SortedList<FC> fc_list; //fc 저장하는 리스트


	SortedList<Album> albumList; //앨범 리스트
	SortedList<People> peopleList; // 사람 리스트
};
