#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "ItemType.h"
#include "SortedList.h"

class EventType {

public:
	EventType()
	{
		name = ""; //콘텐츠 파일명
		event = ""; //이벤트명
	}
	~EventType() {}

	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	string GetName();

	/*
	precondition:  event가 정의돼 있어야 한다
	postcondition:  event를 리턴한다
	*/
	string GetEvent();

	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	void SetName(string inputName);

	/*
	precondition: event가 정의돼 있어야 한다
	postcondition: event를 입력받은 값으로 바꾼다
	*/
	void SetEvent(string inputEvent);

	/*
	precondition: name, kindOfContents, date, peoplem event가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	void SetRecord(string name, string event = "");

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 출력한다
	*/
	void DisplayNameOnScreen();

	/*
	precondition: event가 정의돼 있어야한다
	postcondition:  event를 출력한다
	*/
	void DisplayEventOnScreen();

	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다
	*/
	void DisplayRecordOnScreen(SortedList<ItemType>& master);

	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다
	*/
	void DisplayRecordOnScreen();

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 입력받는다
	*/
	void SetNameFromKB();

	/*
	precondition: event가 정의돼 있어야한다
	postcondition: event를 입력받는다
	*/
	void SetEventFromKB();

	/*
	precondition: 본문의 함수들이 정의돼 있어야한다
	postcondition: 함수들을 호출한다
	*/
	void SetRecordFromKB();

	/*
	precondition: fin이 정의돼 있어야한다
	postcondition: 파일에서 읽어오고 성공하면 1을 리턴한다
	*/
	int ReadDataFromFile(ifstream& fin);// 콘텐츠정보를파일에서읽는함수

	/*
	precondition: fout이 정의돼 있어야 한다
	postcondition: 각 변수들을 파일에 저장하고 성공하면 1을 리턴한다
	*/
	int WriteDataToFile(ofstream& fout);// 콘텐츠정보를파일로출력하는함수

	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	RelationType CompareByName(const EventType& data);// primary key (ID)를기준으로콘텐츠정보를비교하는함수

private:
	string name; //콘텐츠 파일명
	string event; //이벤트명

};