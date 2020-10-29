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
		name = ""; //������ ���ϸ�
		event = ""; //�̺�Ʈ��
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

	int ReadDataFromFile(ifstream& fin);// ���������������Ͽ����д��Լ�
	int WriteDataToFile(ofstream& fout);// ���������������Ϸ�����ϴ��Լ�
	RelationType CompareByName(const EventType& data);// primary key (ID)�������������������������ϴ��Լ�

private:
	string name; //������ ���ϸ�
	string event; //�̺�Ʈ��

};