#pragma once
#include "SortedList.h"
#include<iostream>
#include<string>
#include<fstream>
#include "Event.h"
#include "FC.h"

#define FILENAMESIZE 1024

class Application : public SortedList<FC>{
public:
	Application()
	{
		m_Command = 0;
	}
	~Application() {}
	void Run();
	int GetCommand();
	int AddContents();
	void DisplayAllContents();
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();
	int WriteDataToFile();
	int DeleteContents();
	int ReplaceContents();
	void MakeEmpty();

	//int SearchByName();
	int replaceItem();
	int SearchAllItmeByPeople(ItemType& data);
	int SearchByName_SequenS();

	int SearchByPeople();
	int SearchByName_BinaryS();

	int Add_FC();
	void Delete_FC_list(); //�Էµ� FC�� FC_list���� ����
	void Display_FC_list(); //FC_list�� ����ִ� ������ ȭ�鿡 ���
	void Display_Detail_FC();// Ư�� FC�� �ڼ��� ����(master list�� ����� ����)�� ȭ�鿡 ���
	void runFC();
	void run1();
	void runEvent();
	void Rearrange_FC(); //Ű����κ��� ������ �Է¹޾Ƽ� FC�� ���� ����(���� ��, �̸� ��, ���ֺ��� ��, ��)�� �ٲ۴�.
	

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	SortedList<ItemType> m_List;///< item list.
	int m_Command;///< current command number
	Event event; //�ϳ��� �̺�Ʈ�� ���� �������� ������ ����
	SortedList<FC> fc_list; // ���������� ����Ǵ� 
	UnsortedList<FC> unsortedFC; //���� ������� ����Ǵ� 


};
