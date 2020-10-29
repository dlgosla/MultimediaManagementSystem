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
	void Delete_FC_list(); //입력된 FC를 FC_list에서 삭제
	void Display_FC_list(); //FC_list에 들어있는 정보를 화면에 출력
	void Display_Detail_FC();// 특정 FC의 자세한 정보(master list에 저장된 정보)를 화면에 출력
	void runFC();
	void run1();
	void runEvent();
	void Rearrange_FC(); //키보드로부터 조건을 입력받아서 FC의 보는 순서(들어온 순, 이름 순, 자주보는 순, 등)를 바꾼다.
	

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	SortedList<ItemType> m_List;///< item list.
	int m_Command;///< current command number
	Event event; //하나의 이벤트에 대한 사진들의 정보를 저장
	SortedList<FC> fc_list; // 순차적으로 저장되는 
	UnsortedList<FC> unsortedFC; //들어온 순서대로 저장되는 


};
