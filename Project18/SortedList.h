#pragma once

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 10


class SortedList
{
public:
	SortedList()
	{
		m_Length = 0;
		m_CurPointer = 0;
	}

	~SortedList() {}

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	void ResetList();
	int GetNextItem(ItemType& data);
	int Add(ItemType data);
	int Delete(ItemType data);
	int Replace(ItemType data);
	int Retrieve_SeqS(ItemType& data);
	int Retrieve_BinaryS(ItemType& data);



private:
	ItemType m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};