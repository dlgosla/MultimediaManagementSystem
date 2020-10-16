#pragma once
#include "SortedList.h"
#include<iostream>
#include<string>
#include<fstream>

#define FILENAMESIZE 1024

class Application {
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

	int SearchByName();
	int replaceItem();
	int SearchAllItmeByPeople(ItemType& data);
	int SearchByName_SequenS();

	int SearchByPeople();
	int ReplaceFile();
	int SearchByName_BinaryS();

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	SortedList m_List;///< item list.
	int m_Command;///< current command number
};
