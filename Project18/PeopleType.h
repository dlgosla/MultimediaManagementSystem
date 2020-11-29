#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "ItemType.h"
#include "SortedList.h"

class PeopleType {

public:
	PeopleType();
	~PeopleType();

	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	string GetContentsName();

	/*
	precondition:  event가 정의돼 있어야 한다
	postcondition:  event를 리턴한다
	*/
	string GetPeople();

	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	void SetContentsName(string inputName);

	/*
	precondition: event가 정의돼 있어야 한다
	postcondition: event를 입력받은 값으로 바꾼다
	*/
	void SetPeople(string inputEvent);

	/*
	precondition: name, kindOfContents, date, peoplem event가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	void SetRecord(string cName, string people);


	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소의 자세한 정보를 출력한다
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
	void SetContentsNameFromKB();

	/*
	precondition: event가 정의돼 있어야한다
	postcondition: event를 입력받는다
	*/
	void SetPeopleFromKB();

	/*
	precondition: 본문의 함수들이 정의돼 있어야한다
	postcondition: 함수들을 호출한다
	*/
	void SetRecordFromKB();


	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	RelationType CompareByName(const PeopleType& data);// primary key (ID)를기준으로콘텐츠정보를비교하는함수

private:
	string contentsName; //콘텐츠 파일명
	string people; //콘텐츠에 포함된 사람 이름

};