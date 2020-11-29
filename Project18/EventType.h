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
		name = ""; //������ ���ϸ�
		event = ""; //�̺�Ʈ��
	}
	~EventType() {}

	/*
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	string GetName();

	/*
	precondition:  event�� ���ǵ� �־�� �Ѵ�
	postcondition:  event�� �����Ѵ�
	*/
	string GetEvent();

	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	void SetName(string inputName);

	/*
	precondition: event�� ���ǵ� �־�� �Ѵ�
	postcondition: event�� �Է¹��� ������ �ٲ۴�
	*/
	void SetEvent(string inputEvent);

	/*
	precondition: name, kindOfContents, date, peoplem event�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	void SetRecord(string name, string event = "");

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� ����Ѵ�
	*/
	void DisplayNameOnScreen();

	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition:  event�� ����Ѵ�
	*/
	void DisplayEventOnScreen();

	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ�
	*/
	void DisplayRecordOnScreen(SortedList<ItemType>& master);

	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ�
	*/
	void DisplayRecordOnScreen();

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� �Է¹޴´�
	*/
	void SetNameFromKB();

	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition: event�� �Է¹޴´�
	*/
	void SetEventFromKB();

	/*
	precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
	postcondition: �Լ����� ȣ���Ѵ�
	*/
	void SetRecordFromKB();

	/*
	precondition: fin�� ���ǵ� �־���Ѵ�
	postcondition: ���Ͽ��� �о���� �����ϸ� 1�� �����Ѵ�
	*/
	int ReadDataFromFile(ifstream& fin);// ���������������Ͽ����д��Լ�

	/*
	precondition: fout�� ���ǵ� �־�� �Ѵ�
	postcondition: �� �������� ���Ͽ� �����ϰ� �����ϸ� 1�� �����Ѵ�
	*/
	int WriteDataToFile(ofstream& fout);// ���������������Ϸ�����ϴ��Լ�

	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	RelationType CompareByName(const EventType& data);// primary key (ID)�������������������������ϴ��Լ�

private:
	string name; //������ ���ϸ�
	string event; //�̺�Ʈ��

};