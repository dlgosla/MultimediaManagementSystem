#pragma once
#include "SortedList.h"

//���ã�� ������ Ŭ����
class FC {
private:
	string fileName; //������ ������ �̸�
	int countOfView; //�� �������� �� Ƚ��

public:
	void DisplayRecordOnScreen(BinarySearchTree<ItemType>& master)
	{
		/*
		precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
		postcondition: �� ��Ҹ� ����Ѵ�
		*/
		//master.ResetList();
		ItemType item;
		item.SetName(fileName);
		bool found = false;
		master.RetrieveItem(item,found);
		item.DisplayRecordOnScreen();
	}


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