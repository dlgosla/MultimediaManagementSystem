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
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	string GetContentsName();

	/*
	precondition:  event�� ���ǵ� �־�� �Ѵ�
	postcondition:  event�� �����Ѵ�
	*/
	string GetPeople();

	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	void SetContentsName(string inputName);

	/*
	precondition: event�� ���ǵ� �־�� �Ѵ�
	postcondition: event�� �Է¹��� ������ �ٲ۴�
	*/
	void SetPeople(string inputEvent);

	/*
	precondition: name, kindOfContents, date, peoplem event�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	void SetRecord(string cName, string people);


	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ����� �ڼ��� ������ ����Ѵ�
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
	void SetContentsNameFromKB();

	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition: event�� �Է¹޴´�
	*/
	void SetPeopleFromKB();

	/*
	precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
	postcondition: �Լ����� ȣ���Ѵ�
	*/
	void SetRecordFromKB();


	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	RelationType CompareByName(const PeopleType& data);// primary key (ID)�������������������������ϴ��Լ�

private:
	string contentsName; //������ ���ϸ�
	string people; //�������� ���Ե� ��� �̸�

};