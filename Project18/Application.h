#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "SortedLinkedList.h"
#include "SortedList.h"
#include "Event.h"
#include "FC.h"
#include "Album.h"
#include "People.h"
#include "BinarySearchTree.h"

#define FILENAMESIZE 1024

class Application {
public:

	/*
	* pre: fc_pic����Ʈ�� ���ǵ� �־���Ѵ�
	* post: fc_picList�� �ڼ��� ������ ������ ȭ�鿡 ����Ѵ�
	*/
	void Display_Detail_Pic_FC();

	/*
	* pre: fc_vdeio����Ʈ�� ���ǵ� �־���Ѵ�
	* post: fc_videoList�� �ڼ��� ������ ������ ȭ�鿡 ����Ѵ�
	*/
	void Display_Detail_Video_FC();

	/*
	* Ű����� ���� ������ �Է¹޾Ƽ� Ư�� ��� ��ü ������ �����ؼ� �˻�
	* pre: �������Ʈ�� �̺�Ʈ ����Ʈ�� ���ǵ� �־����
	* post: ����� �̺�Ʈ �̸��� �Է¹ް� �� �� ������Ű�� ���� ã��
	*/
	void searchPeopleInEvent();

	/*
	* Ű����� ���� ������ �Է¹޾Ƽ� Ư�� ��� ��ü ������ �����ؼ� �˻�
	* pre: �������Ʈ�� �̺�Ʈ ����Ʈ�� ���ǵ� �־����
	* post: ����� �̺�Ʈ �̸��� �Է¹ް� ��� ����Ʈ �ȿ��� �Էµ� �̺�Ʈ ���� ã��
	*/
	void searchEventInPeople();

	/*
	* ppst: peo ���� �޴�
	*/
	void runPeople();

	/*
	* pre: �߰��� ��� �̸��� people ����Ʈ�� ����� ��
	* post: �����ü ���� ������ ����Ʈ�� �������� �߰���
	*/
	void addPeople(string pName, string contentsName);
	/*
	* pre: ��� ����Ʈ�� �����ؾ���
	* post: �����ϴ� ��� �����ü�� �׿� ���ϴ� ������ ���
	*/
	void printAllGroup();

	/*
	* pre: ��� ����Ʈ�� �����ؾ���
	* post: Ư�� ����� ���Ե� ���������� ����ϰ� �����ü�� ��ȯ
	*/
	People printPeople();

	/*
	* post:�ٹ��� ���õ� �޴�
	*/
	void runAlbum();
	/*
	* pre: �����ϰ��� �ϴ� �� ������ ����Ʈ�� �־����
	* post: �ٹ����� �������� ������
	*/
	void deleteContentsInAlbum();

	/*
	* post: �߰��ϰ��� �ϴ� �� ������ ����Ʈ�� �������
	* post; �ٹ��� �������� �߰���
	*/
	void addContentsInAlbum();

	/*
	* pre: �ٹ� ����Ʈ�� �־���� �Ȱ��� �ٹ����� ������ �ȵ�
	* post; �ٹ��� �߰��Ѵ�.
	*/
	void addAlbum();

	/*
	* pre: �ٹ� ����Ʈ�� �־���� �Ȱ��� �ٹ����� �־�����
	* post; �ٹ��� �����Ѵ�
	*/
	int deleteAlbum();

	/*
	* pre: �ٹ� ����Ʈ�� �־����
	* post; ��� �ٹ��� �ٹ� �� �������� ���
	*/
	void printAllAlbum();


	/*
	* pre: �̺�Ʈ�� �����ؾ���
	* post: �����ϴ� ��� �̺�Ʈ�� �ű� ���ϴ� ������ ���
	*/
	void printAllEvent();

	/*
	* pre:�̺�Ʈ ���� �̺�Ʈ ����Ʈ�� ����� ��
	* post: ����ڿ��� �̺�Ʈ���� �Է¹޾� �ϳ��� �̺�Ʈ �׷��� �����ϰ� ������ 1 ����
	*/
	int deleteEvent();

	/*
	* pre:�̺�Ʈ ���� �̺�Ʈ ����Ʈ�� ����� ��
	* post: �� �̺�Ʈ�� ������ �̺�Ʈ Ÿ���� ��带 ����� ������ 1 ����
	*/
	int addEvent();

	/*
	�������� �Է¹޾Ƽ� �����͸���Ʈ, �̺�Ʈ����Ʈ, FC����Ʈ�� �����Ѵ�
	precondition: primary key�� �ߺ��Ǹ� �ȵȴ�
	postcondition: �߰��ϰ� �����ϸ� 1 �����ϸ� 0�� ��ȯ�Ѵ�
	*/
	int AddContents();

	/*
	* �̺�Ʈ �̸��� �Է¹޾Ƽ� �ű� �Ҽӵ� �������� �ڼ��� ������ ���
	* pre: �̺�Ʈ ����Ʈ�� �ش� �̺�Ʈ Ŭ������ �־�� �Ѵ�
	* post: �ش��̺�Ʈ�� �Ҽӵ� �������� �ڼ��� ������ ���
	*/
	Event FindNDisplayEvent();

	/*
	������
	*/
	Application();
	/*
	* �Ҹ���
	*/
	~Application();

	/*
	* �⺻ �޴�â
	*/
	void Run(); //�޴�

	/*
	* �⺻�޴�â���� ������� ������ ����
	*/
	int GetCommand();

	/*
	* pre: �̺�Ʈ�� �����ؾ���
	* post: �����ϴ� ��� �̺�Ʈ�� �ű� ���ϴ� ������ ���
	*/
	void DisplayAllContents();
	int DeleteContents();
	void MakeEmpty();

	//int SearchByName();

	int SearchByName_SequenS();

	int SearchByPeople(); //������� ã��
	int SearchByName_BinaryS(); //�������̸��� Ű���ؼ� �����˻����� ã��

	/*
	* pre: m_List�� ���ǵ� �־�� �Ѵ�. �̹� FC����Ʈ�� ����� �ִ� �������� �Է��ϸ� �ȵȴ�.
	*	��ü ������ ����߿� �ش� �������� �־���Ѵ�.
	* post: ��ġ�ϴ� �����͸� ã�� �����ϸ� 1 �����ϸ� 0�� ����
	*/
	int Add_FC();

	/*
	* pre: �Էµ� FC�� FC����Ʈ�� �־�� �Ѵ�
	* post: ��ġ�ϴ� �����͸� �����Ѵ�
	*/
	void Delete_FC_list(); //�Էµ� FC�� FC_list���� ����

	/*
	* pre: fc����Ʈ�� ���ǵ� �־���Ѵ�
	* post: fc_list�� ������ ȭ�鿡 ����Ѵ�
	*/
	void Display_FC_list(); //FC_list�� ����ִ� ������ ȭ�鿡 ���

	/*
	* pre: fc����Ʈ�� ���ǵ� �־���Ѵ�
	* post: fc_list�� �ڼ��� ������ ȭ�鿡 ����Ѵ�
	*/
	void Display_Detail_FC();// Ư�� FC�� �ڼ��� ����(master list�� ����� ����)�� ȭ�鿡 ���

	/*
	* pre: fc����Ʈ�� ���ǵ� �־���Ѵ�
	* post: fc_list�� �ڼ��� ������ ȭ�鿡 ����Ѵ�
	*/

	/*
	* fc ���� �޴�â
	*/
	void runFC(); //FC ���� �޴� 
	void run1(); //ó�� �� �޴�
	void runEvent(); //�̺�Ʈ ���� �޴�

	//void FindNDisplayEvent(); //�̺�Ʈ �̸��� �Է¹޾Ƽ� �ű� �Ҽӵ� �������� �ڼ��� ������ ���



private:
	ifstream m_InFile;///< input file descriptor. 
	ofstream m_OutFile;///< output file descriptor.
	BinarySearchTree<ItemType> m_List;///< item list. �����͸���Ʈ
	int m_Command;///< current command number

	
	SortedLinkedList<Event> eventList; //�� �̺�Ʈ ���� ����Ʈ�� ����
	SortedList<FC> fc_videoList; // video fc�� ���� �����ϴ� ����Ʈ
	SortedList<FC> fc_picList; //���� fc������ �����ϴ� ����Ʈ
	SortedList<FC> fc_list; //fc �����ϴ� ����Ʈ


	SortedList<Album> albumList; //�ٹ� ����Ʈ
	SortedList<People> peopleList; // ��� ����Ʈ
};
