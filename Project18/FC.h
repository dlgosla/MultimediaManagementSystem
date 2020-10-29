#pragma once
#include<iostream>
#include<string>
using namespace std;

class FC {
private:
	string fileName; //������ ������ �̸�
	//string memo; //������ ������ ����
	int countOfView; //�� �������� �� Ƚ��

public:
	void DisplayRecordOnScreen(); //������ �����
	/*
	* pre: FC�� ��������� ���ǵ� �־����
	* post: ������ ����ϰ� �ƹ��͵� ��ȯ���� ����
	*/
	void setRecord(string fileName, int countOfView = 0);//������ �Է���
	/*
	* pre:���� ����
	* post: ������ �����ϰ� �ƹ��͵� ��ȯ���� ����
	*/
	string getFileName(); //fileName�� ��ȯ
	/*
	* pre:fileName�� ���ǵ� �־����
	* post: fileName�� ��ȯ
	*/
	void view();
	/*
	* pre: countOfView�� ���ǵ� �־��Ѵ�
	* post: countOfView�� �ѹ� �ø���.
	*/
	int CompareByName(const FC& data);
	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less(0), grater(1), equal(2)�� ��ȯ�Ѵ�
	*/
	int getCountOfView();

	


};