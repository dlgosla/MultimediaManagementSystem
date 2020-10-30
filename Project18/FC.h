#pragma once
#include<iostream>
#include<string>
using namespace std;

//���ã�� ������ Ŭ����
class FC {
private:
	string fileName; //������ ������ �̸�
	//string memo; //������ ������ ����
	int countOfView; //�� �������� �� Ƚ��

public:
		/*
	* pre: FC�� ��������� ���ǵ� �־����
	* post: ������ ����ϰ� �ƹ��͵� ��ȯ���� ����
	*/
	void DisplayRecordOnScreen(); //������ �����

	/*
	* pre:���� ����
	* post: ������ �����ϰ� �ƹ��͵� ��ȯ���� ����
	*/
	void setRecord(string fileName, int countOfView = 0);//������ �Է���
	
	/*
	* pre:fileName�� ���ǵ� �־����
	* post: fileName�� ��ȯ
	*/
	string getFileName(); //fileName�� ��ȯ
	
	/*
	* pre: countOfView�� ���ǵ� �־��Ѵ�
	* post: countOfView�� �ѹ� �ø���.
	*/
	void view(); // �������� �̸��� �Է¹޾Ƽ� �ش� �������� view�� 1���� ��Ŵ
	
	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less(0), grater(1), equal(2)�� ��ȯ�Ѵ�
	*/
	int CompareByName(const FC& data);  //name�� �������� �� �����͸� ��
	
	/*
	precondition: countOfView�� ���ǵ� �־���Ѵ�
	postcondition: countOfView�� �����Ѵ�
	*/
	int getCountOfView();

	


};