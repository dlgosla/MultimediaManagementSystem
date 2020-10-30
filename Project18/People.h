#pragma once
#pragma once
#include<iostream>
#include "SortedList.h"
#include "PeopleType.h"
#include "UnsortedList.h"
#include<string>
using namespace std;

/*
* ������� ����
*/
class People {
private:
	string PeopleName; // ��� �̸�
	int length; //��� ����� �� ����
	UnsortedList<PeopleType> contentsList; // Ư�� ����� ���Ե� �׷���� ����

public:
	People();
	~People();

	/*
	* pre:length�� ���� �� �־����
	* post: length ��ȯ
	*/
	int getLength();

	/*
	* pre: item�� key�� ��ġ�ϴ� �����Ͱ� �־�� ��
	* post: item�� key�� ��ġ�ϴ� ������ ������ item���� �ٲ�
	*/
	void replace(PeopleType item);

	/*
	* ������ �����ε�
	* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
	*/
	bool operator>(People item);
	/*
	* post: �� ���� key���� ������ true �ƴϸ� false�� ����
	*/
	bool operator==(People item);

	/*
		pre: PeopleName�� ���� �� �־�� �Ѵ�
		post: PeopleName�� ����
	*/
	string getPeopleName();

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
	int Add(PeopleType e);  //people List�� ������ �߰�
	/*
	* pre:peopleList�� ���ǵ� �־����, ������ key�� ������ �ȵ�
	* post: ������ 1 ��ȯ
	*/
	int Delete(PeopleType e);  //people List�� ������ ����
	/*
	* pre:peopleList�� ���ǵ� �־���� ������ �������� key�� ��ġ�ϴ� key�� �־����
	* post: ������ 1 ��ȯ
	*/
	int Retrieve(PeopleType e);  //people List ������ �˻�
	/*
	* pre:peopleList�� ���ǵ� �־����
	* post: ������ 1 , ���н� 0��ȯ
	*/

};