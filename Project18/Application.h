#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "SortedLinkedList.h"
#include "SortedList.h"
#include "Event.h"
#include "FC.h"
#include "People.h"
#include "Album.h"

#define FILENAMESIZE 1024

class Application {
public:
	/*
	* pre:none
	* post: �ٹ��� ���õ� �޴�
	*/
	void runAlbum() {
		while (1) {
			cout << "======�ٹ� �޴�=====" << endl;
			cout << "1. �ٹ� �̸� �߰�" << endl;
			cout << "2. �ٹ� �̸� ����" << endl;
			cout << "3. �ٹ��� ���� �߰�" << endl;
			cout << "4. �ٹ��� ���� ����" << endl;
			cout << "�ٸ�����: �ڷΰ���" << endl;
			cout << "==================" << endl;

			int input;
			cout << ">> ";
			cin >> input;

		}
		
	}

	/*
	* pre:none
	* post: �̸��� �Է¹޾� �� �̸��� �ٹ������� ������ �ٹ��� �߰��Ѵ�
	*/
	void addAlbum() {
		
	}

	/*
	* pre: �ٹ����� �ٹ�����Ʈ�� �־�� �Ѵ�, �� �ٹ� �׷쿡 �߰��� �������� �ߺ��� �������� ������Ѵ�
	* post: Ư�� �ٹ����� �Է¹޾� �� �ٹ��׷쿡 �������� �߰��Ѵ�
	*/
	void addContentsInAlbum() {}

	/*
	* pre: �ٹ����� �ٹ� ����Ʈ�� �־�� �Ѵ�, �� �ٹ��ȿ� �ش� �������� �־���Ѵ�
	* post: �ٹ��̸��� ������ �̸��� Ű����� �Է¹޾Ƽ� �� �ٹ��ȿ��� �ش� �������� �����Ѵ�
	*/
	void deleteContentsInAlbum() {}

	/*
	* pre: �ٹ��� �ϳ��̻� �����ؾ��Ѵ�
	* post: �� �̸��� �ٹ������� ������ �ٹ��� �����Ѵ�
	*/
	void deleteAlbum() {}


	/*
	* pre:none
	* post: location ����Ʈ ������ ������ Ž���Ѵ�
	*/
	void searchInLocation() {

	}

	/*
	* pre:none
	* post: FC ����Ʈ ������ ������ Ž���Ѵ�
	*/
	void searchInFC() {

	}

	/*
	* pre:none
	* post: PHOTO Ÿ�� FC ����Ʈ ������ ������ Ž���Ѵ�
	*/
	void searchInPhotoFC() {

	}

	/*
	* pre:none
	* post: VideoŸ�� FC ����Ʈ ������ ������ Ž���Ѵ�
	*/
	void searchInVideoFC() {

	}

	/*
	* pre:none
	* post: ���� Ÿ�� FC�� ����Ѵ�
	*/
	void printPhotoFC() {

	}

	/*
	* pre: none
	* post:���� Ÿ�� FC�� ����Ѵ�
	*/
	void printVideoFC() {

	}

	/*
	* Ű����� ���� ������ �Է¹޾Ƽ� Ư�� �̺�Ʈ ��ü ������ �����ؼ� �˻�
	* pre: �̺�Ʈ ����Ʈ�� �̺�Ʈ�� ���ǵ� �־����
	* post: Ư�� �̺�Ʈ �̸��� �Է¹ް� �� �̺�Ʈ �׷� ������ �˻�
	*/
	void SearchInEvent() {

	}


	/*
	* Ű����� ���� ������ �Է¹޾Ƽ� Ư�� ��� ��ü ������ �����ؼ� �˻�
	* pre: ��� ����Ʈ�� �� ����� ���ǵ� �־����
	* post: Ư�� ����� �̸��� �Է¹ް� �� ��� �׷� ������ �˻�
	*/
	void SearchInPeople() {

	}


	void runPeople()//people �޴�
	{

	}

	/*
	* pre: people�� �����ؾ���
	* post: �����ϴ� ��� ����� �ű� ���ϴ� ������ ���
	*/
	void printAllPeople() {

	}

	/*
	* pre: �� ����� �̸��� people ����Ʈ�� �־�� ��
	* post: ����ڿ��� ����̸��� �Է¹޾� �ϳ��� people �׷��� �����ϰ� ������ 1 ����
	*/
	int deletePeople() {

	}

	/*
	* pre: �߰��� ��� �̸��� people ����Ʈ�� ����� ��
	* post: �� �̺�Ʈ�� ������ people Ÿ���� ��带 ����� ������ 1 ����
	*/
	int addPeople(){
	}

	/*
	* ��� �̸��� �Է¹޾Ƽ� �ű� �Ҽӵ� �������� �ڼ��� ������ ���
	* pre: people ����Ʈ�� �ش� people Ŭ������ �־�� �Ѵ�
	* post: �ش�People�� �Ҽӵ� �������� �ڼ��� ������ ���
	*/
	void FindNDisplayPeople() {

	}


	/*
	* pre: �̺�Ʈ�� �����ؾ���
	* post: �����ϴ� ��� �̺�Ʈ�� �ű� ���ϴ� ������ ���
	*/
	void printAllEvent();

	/*
	* pre:�̺�Ʈ ���� �̺�Ʈ ����Ʈ�� �־����
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
	void FindNDisplayEvent();

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
	* pre: �������� �����ؾ���
	* post: �����ϴ� ��� ������ ���
	*/
	void DisplayAllContents();

	/*
	precondition: fileName�� ������ �����ؾ��Ѵ�
	postcondition: ������ �������� 1 ���������� 0�� ��ȯ
	*/
	int OpenInFile(char* fileName);

	/*
	precondition: fileName�� ������ �����ؾ��Ѵ�
	postcondition: ������ �������� 1 ���������� 0�� ��ȯ
	*/
	int OpenOutFile(char* fileName);

	/*
	precondition: m_InFile�� ���ǵ� �־�� �Ѵ�. filename�� ��ġ�ϴ� ������ �־�� �Ѵ�
	postcondition: ���Ͽ��� �����͸� �а� �����ϸ� 1 �����ϸ� 0�� ��ȯ
	���ϸ��� �Է¹޾� �ش� �������� ��� ������ ���
	*/
	int ReadDataFromFile();

	/*
	precondition: m_OutFile�� ���ǵ� �־�� �Ѵ�.
	postcondition: ���Ͽ� �����ϰ� �����ϸ� 1 �����ϸ� 0�� ��ȯ
	*/
	int WriteDataToFile();

	/*
		precondition: data�� m_List�ȿ� �־�� �Ѵ�
		postcondition: m_List���� data�� ��ġ�ϴ� ���ڵ带 �����ϰ� �����ϸ� 1, �����ϸ� 0�� ��ȯ
	*/
	int DeleteContents();

	/*
		precondition: m_List�� ���ǵ� �־�� �Ѵ�, m_List�� data�� primary key�� ��ġ�ϴ� ���� �־�� �Ѵ�
		postcondition: primary key�� ��ġ�ϴ� ���ڵ带 data�� ������ ��ü�ϰ� ������ 1 ���н� 0�� ��ȯ
	*/
	int ReplaceContents();

	/*
	precondition: m_List�� ���ǵ� �־�� �Ѵ�
	postcondition: �迭�� ����
	*/
	void MakeEmpty();

	//int SearchByName();

	/*
		precondition: m_List�� ���ǵ� �־�� �Ѵ�, m_List�� data�� primary key�� ��ġ�ϴ� ���� �־�� �Ѵ�
		postcondition: primary key�� ��ġ�ϴ� ���ڵ带 data�� ������ ��ü�ϰ� ������ 1 ���н� 0�� ��ȯ
	*/
	int replaceItem();

	/*
	* pre: ���� ����
	* post: ã���� 1 ��ã���� 0 ��ȯ
	*/
	int SearchAllItmeByPeople(ItemType& data);

	/*
	* pre: m_List�� ���ǵ� �־�� �Ѵ�
	* post: ��ġ�ϴ� �����͸� ã�� �����ϸ� 1 �����ϸ� 0�� ����
	*/
	int SearchByName_SequenS();

	/*
	* pre: ���� ����
	* post: �Էµ� �̸��� ���Ե� �������� ��� ã�� ���� 1 ���� 0 ��ȯ
	*/
	int SearchByPeople(); //������� ã��

	/*
	* pre: m_List�� ���ǵ� �־�� �Ѵ�
	* post: ��ġ�ϴ� �����͸� ã�� �����ϸ� 1 �����ϸ� 0�� ����
	*/
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
	void Rearrange_FC(); //Ű����κ��� ������ �Է¹޾Ƽ� FC�� ���� ����(���� ��, �̸� ��, ���ֺ��� ��, ��)�� �ٲ۴�.

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
	SortedList<ItemType> m_List;///< item list. �����͸���Ʈ
	int m_Command;///< current command number

	SortedLinkedList<Event> eventList; //�� �̺�Ʈ ���� ����Ʈ�� ����
	SortedList<FC> fc_list; // ���������� ����Ǵ� 
	UnsortedList<FC> unsortedFC; //���� ������� ����Ǵ� 

	SortedList<FC> fc_photo; //������ fc����Ʈ
	SortedList<FC> fc_video; //������ fc����Ʈ
	UnsortedList<People> peopleList; //����� ����Ʈ
	UnsortedList<Album> albumList; //�ٹ� ����Ʈ




};
