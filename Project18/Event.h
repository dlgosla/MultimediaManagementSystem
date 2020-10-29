#include<iostream>
#include "SortedList.h"
#include "EventType.h"
#include "UnsortedList.h"
using namespace std;

class Event {
private:
	string eventName; //�̺�Ʈ �̸�
	string description; //�̺�Ʈ ����
	int countOfEvent; //�̺�Ʈ ����
	SortedList<EventType> eventList; // �̺�Ʈ����Ʈ

public:
	Event() {
		eventName = "";
		description = "";
		countOfEvent = 0;
	}
	void setRecord(string e_name, string desc, int count);
	/*
	* pre: �� ��������� ���ǵ� �־����
	* post: ������ �����
	*/
	void printRecord();
	/*
	* ��� ������ ������
	*/
	int Add();  //eventList�� ������ �߰�
	/*
	* pre:eventList�� ���ǵ� �־����
	* post: ������ 1 ��ȯ
	*/
	int Delete();  //eventList�� ������ ����
	/*
	* pre:eventList�� ���ǵ� �־����
	* post: ������ 1 ��ȯ
	*/
	int Retrieve();  //eventList ������ �˻�
	/*
	* pre:eventList�� ���ǵ� �־����
	* post: ������ 1 , ���н� 0��ȯ
	*/

};
