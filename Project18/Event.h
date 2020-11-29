#pragma once
#include<iostream>
#include "SortedList.h"
#include "EventType.h"
#include "UnsortedList.h"
#include<string>
using namespace std;


class Event {
private:
	string eventName; // �̺�Ʈ �̸�
	string description; //�̺�Ʈ ����
	int countOfEvent; //�̺�Ʈ ����
	UnsortedList<EventType> contentsList;

public:
	Event();
	~Event();

	/*
	* post: ����Ʈ ����
	*/
	UnsortedList<EventType> getList();

	/*
	* pre:countOfEvent�� ���� �� �־����
	* post: countOfEvent ��ȯ
	*/
	int getCountOfEvent();

	/*
	* pre: item�� key�� ��ġ�ϴ� �����Ͱ� �־�� ��
	* post: item�� key�� ��ġ�ϴ� ������ ������ item���� �ٲ�
	*/
	void replace(EventType item);

	/*
	* ������ �����ε�
	* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
	*/
	bool operator>(Event item);
	/*
	* post: �� ���� key���� ������ true �ƴϸ� false�� ����
	*/
	bool operator==(Event item);

	/*
		pre: eventName�� ���� �� �־�� �Ѵ�
		post: eventName�� ����
	*/
	string getEventName();

	/*
	* post: �� �Ķ������ ���� ��� ������ ������
	*/
	void setRecord(string e_name, string desc = "", int count = 0);
	/*
	* pre: �� ��������� ���ǵ� �־����
	* post: ������ �����
	*/
	void printRecord(SortedList<ItemType>& master);
	/*
	* ��� ������ ������
	*/
	int Add(EventType e);  //eventList�� ������ �߰�
	/*
	* pre:eventList�� ���ǵ� �־����
	* post: ������ 1 ��ȯ
	*/
	int Delete(EventType eName);  //eventList�� ������ ����
	/*
	* pre:eventList�� ���ǵ� �־����
	* post: ������ 1 ��ȯ
	*/
	int Retrieve(EventType e);  //eventList ������ �˻�
	/*
	* pre:eventList�� ���ǵ� �־����
	* post: ������ 1 , ���н� 0��ȯ
	*/

};
