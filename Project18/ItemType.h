#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

//�� �������� ��ü������ �����ϴ� Ŭ����
class ItemType {

public:
	/*
	* ������ �����ε�
	* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
	*/
	bool operator>(ItemType item);

	/*
	* post: �� ���� key���� ������ true �ƴϸ� false�� ����
	*/
	bool operator==(ItemType item);

	/*
	* ������
	*/
	ItemType();

	/*
	* �Ҹ���
	*/
	~ItemType();

	/*
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	string GetName();

	/*
	precondition: kindOfContents�� ���ǵ� �־�� �Ѵ�
	postcondition: kindOfContents�� �����Ѵ�
	*/
	int GetkindOfContents();
	/*
	precondition: date�� ���ǵ� �־�� �Ѵ�
	postcondition: date�� �����Ѵ�
	*/
	string GetDate();

	/*
	precondition: people�� ���ǵ� �־�� �Ѵ�
	postcondition: people�� �����Ѵ�
	*/
	string GetPeople();

	/*
	precondition:  event�� ���ǵ� �־�� �Ѵ�
	postcondition:  event�� �����Ѵ�
	*/
	string GetEvent();

	/*
	precondition:  classification�� ���ǵ� �־�� �Ѵ�
	postcondition:  classification�� �����Ѵ�
	*/
	int GetClassification();

	/*
	precondition:  memo�� ���ǵ� �־�� �Ѵ�
	postcondition:  memo�� �����Ѵ�
	*/
	string GetMemo();

	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	void SetName(string inputName);

	/*
	precondition: kindOfContents�� ���ǵ� �־�� �Ѵ�
	postcondition: kindOfContents�� �Է¹��� ������ �ٲ۴�
	*/
	void SetkindOfContents(int inputKindOfContent);

	/*
precondition: date�� ���ǵ� �־�� �Ѵ�
postcondition: date�� �Է¹��� ������ �ٲ۴�
*/
	void SetDate(string inputDate);

	/*
	precondition:  people�� ���ǵ� �־�� �Ѵ�
	postcondition: people�� �Է¹��� ������ �ٲ۴�
	*/
	void SetPeople(string inputPeople);

	/*
	precondition: event�� ���ǵ� �־�� �Ѵ�
	postcondition: event�� �Է¹��� ������ �ٲ۴�
	*/
	void SetEvent(string inputEvent);

	/*
	precondition: classification�� ���ǵ� �־�� �Ѵ�
	postcondition: classification�� �Է¹��� ������ �ٲ۴�
	*/
	void SetClassification(int inputClassification);

	/*
	precondition: memo�� ���ǵ� �־�� �Ѵ�
	postcondition: memo�� �Է¹��� ������ �ٲ۴�
	*/
	void setMemo(string inputMemo);

	/*
	precondition: name, kindOfContents, date, peoplem event�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	void SetRecord(string name, int kindOfContents, string data, string people, string event, int  inputClassification, string inputMeno);

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� ����Ѵ�
	*/
	void DisplayNameOnScreen();

	/*
	precondition: kindOfContents�� ���ǵ� �־���Ѵ�
	postcondition: kindOfContents�� ����Ѵ�
	*/
	void DisplayKindOnScreen();

	/*
	precondition: date�� ���ǵ� �־���Ѵ�
	postcondition: date�� ����Ѵ�
	*/
	void DisplayDateOnScreen();

	/*
	precondition: people�� ���ǵ� �־���Ѵ�
	postcondition: people�� ����Ѵ�
	*/
	void DisplayPeopleOnScreen();

	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition:  event�� ����Ѵ�
	*/
	void DisplayEventOnScreen();

	/*
precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
postcondition: �� ��Ҹ� ����Ѵ�
*/
	void DisplayRecordOnScreen();

	/*
	precondition: classification�� ���ǵ� �־���Ѵ�
	postcondition: classification�� �Է¹޴´�
	*/
	void DisplayClassificationOnScreen();

	/*
	precondition: memo�� ���ǵ� �־���Ѵ�
	postcondition:  memo�� ����Ѵ�
	*/
	void DisplayMemoOnScreen();

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� �Է¹޴´�
	*/
	void SetNameFromKB();

	/*
	precondition: kindOfContents�� ���ǵ� �־���Ѵ�
	postcondition: kindOfContents�� �Է¹޴´�
	*/
	void SetKindFromKB();

	/*
	precondition: date�� ���ǵ� �־���Ѵ�
	postcondition: date�� �Է¹޴´�
	*/
	void SetDateFromKB();

	/*
	precondition: people�� ���ǵ� �־���Ѵ�
	postcondition: people�� �Է¹޴´�
	*/
	void SetPeopleFromKB();

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
	precondition: classification�� ���ǵ� �־���Ѵ�
	postcondition: classification�� �Է¹޴´�
	*/
	void SetClassificationFromKB();

	/*
	precondition: memo�� ���ǵ� �־���Ѵ�
	postcondition: memo�� �Է¹޴´�
	*/
	void SetMemoFromKB();

	/*
	precondition: fin�� ���ǵ� �־���Ѵ�
	postcondition: ���Ͽ��� �о���� �����ϸ� 1�� �����Ѵ�
	*/
	int ReadDataFromFile(ifstream& fin);// �л����������Ͽ����д��Լ�

	/*
	precondition: fout�� ���ǵ� �־�� �Ѵ�
	postcondition: �� �������� ���Ͽ� �����ϰ� �����ϸ� 1�� �����Ѵ�
	*/
	int WriteDataToFile(ofstream& fout);// �л����������Ϸ�����ϴ��Լ�

	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	RelationType CompareByName(const ItemType& data);// primary key (ID)�����������л����������ϴ��Լ�

private:
	string name; //������ ���ϸ�
	int kindOfContents; //������ ���� (1=���� 2=������..)
	string date; //������¥�� �ð�
	string people; //�������� ���Ե� ���
	string event; //�̺�Ʈ��
	int classification; // �������� ���� (�ι� ��� ..)
	string memo; //������ ����


};