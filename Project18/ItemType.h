#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
class ItemType {

public:
	ItemType()
	{
		name = ""; //������ ���ϸ�
		kindOfContents = -1; //������ ����
		date = ""; //������¥�� �ð�
		people = ""; //�������� ���Ե� ���
		event = ""; //�̺�Ʈ��
	}
	~ItemType() {}
	string GetName();
	int GetkindOfContents();
	string GetDate();
	string GetPeople();
	string GetEvent();
	int GetClassification();
	string GetMemo();

	void SetName(string inputName);
	void SetkindOfContents(int inputKindOfContent);
	void SetDate(string inputDate);
	void SetPeople(string inputPeople);
	void SetEvent(string inputEvent);
	void SetClassification(int inputClassification);
	void setMemo(string inputMemo);
	void SetRecord(string name, int kindOfContents, string data, string people, string event, int  inputClassification, string inputMeno);

	void DisplayNameOnScreen();
	void DisplayKindOnScreen();
	void DisplayDateOnScreen();
	void DisplayPeopleOnScreen();
	void DisplayEventOnScreen();
	void DisplayRecordOnScreen();
	void DisplayClassificationOnScreen();
	void DisplayMemoOnScreen();

	void SetNameFromKB();
	void SetKindFromKB();
	void SetDateFromKB();
	void SetPeopleFromKB();
	void SetEventFromKB();
	void SetRecordFromKB();// Ű������л������Է��Լ�
	void SetClassificationFromKB();
	void SetMemoFromKB();

	int ReadDataFromFile(ifstream& fin);// �л����������Ͽ����д��Լ�
	int WriteDataToFile(ofstream& fout);// �л����������Ϸ�����ϴ��Լ�
	RelationType CompareByName(const ItemType& data);// primary key (ID)�����������л����������ϴ��Լ�

private:
	string name; //������ ���ϸ�
	int kindOfContents; //������ ���� (���� ������..)
	string date; //������¥�� �ð�
	string people; //�������� ���Ե� ���
	string event; //�̺�Ʈ��
	int classification; // �������� ���� (�ι� ��� ..)
	string memo; //������ ����
	

};