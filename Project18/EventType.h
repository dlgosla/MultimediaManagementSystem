#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "ItemType.h"

class EventType {

public:
	EventType()
	{
		name = ""; //콘텐츠 파일명
		event = ""; //이벤트명
	}
	~EventType() {}
	string GetName();
	string GetEvent();


	void SetName(string inputName);
	void SetEvent(string inputEvent);
	void SetRecord(string name, string event);

	void DisplayNameOnScreen();
	void DisplayEventOnScreen();
	void DisplayRecordOnScreen();

	void SetNameFromKB();
	void SetEventFromKB();
	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);// 콘텐츠정보를파일에서읽는함수
	int WriteDataToFile(ofstream& fout);// 콘텐츠정보를파일로출력하는함수
	RelationType CompareByName(const EventType& data);// primary key (ID)를기준으로콘텐츠정보를비교하는함수

private:
	string name; //콘텐츠 파일명
	string event; //이벤트명

};