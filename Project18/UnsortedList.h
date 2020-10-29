#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

/**
*	array based simple unsorted list.
*/
#define MAXSIZE 10

template<typename T>
class UnsortedList
{
public:
	UnsortedList()
	{
		
	//	cout << "MAXSIZE: ";
	//	cin >> MAXSIZE;
		m_Array = new T[MAXSIZE];
	}


	bool isFull()
	{
		/*
			precondition: m_Array가 정의돼있어야한다
			postcondition: 꽉찼으면 true, 아니면 false를 리턴한다
		*/
		if (m_Length > MAXSIZE - 1)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		/*
			precondition: m_Array가 정의돼 있어야함
			postcondition: 배열이 비었으면 true, 안비었으면 false를 리턴
		*/

		if (m_Length == 0)
			return true; //비었음
		return false; //안비었음
	}

	void DisplayRecord()
	{
		for (int i = 0; i < m_Length; i++)
		{
			m_Array[i].DisplayRecordOnScreen();
		}

	}

	int GetLength()
	{
		/*
			precondition: m_Array가 정의돼있어야한다
			postcondition: m_Length를 반환한다
		*/
		return m_Length;
	}


	int Add(T data)
	{
		/*
		precondition: m_Array가 정의돼있어야한다, data가 m_Array에 없어야 한다
		postcondition: 맨 뒤에 data를 추가하고 성공하면 1, 실패하면 0을 반환
		*/
		if (!isFull())
		{
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		else
			return 0;
	}
	
	int Delete(T data)
	{
		/*
			precondition: m_Array에 data가 있어야 한다
			postcondition: m_Array에서 data와 일치하는 것을 찾아 순서를 지키면서 삭제
						   성공하면 1, 실패하면 0을 반환
		*/
		if (isEmpty())
			return 0;

		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i].CompareByName(data) == EQUAL)
			{
				for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
					m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
				m_Length--;	//아이템 개수를 하나 줄임
				return 1;	//성공(1)을 리턴
			}
			return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴

		}
	}

	void ResetList()
	{
		/*
			precondition: m_CurPointer가 정의돼있어야 한다
			postcondition: m_CurPointer 를 -1로 설정한다
		*/
		m_CurPointer = -1;
	}


private:
	T *m_Array;  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
	//int MAXSIZE;
};

#endif	// _UNSORTEDLIST_H