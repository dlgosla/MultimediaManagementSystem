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
			precondition: m_Array�� ���ǵ��־���Ѵ�
			postcondition: ��á���� true, �ƴϸ� false�� �����Ѵ�
		*/
		if (m_Length > MAXSIZE - 1)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		/*
			precondition: m_Array�� ���ǵ� �־����
			postcondition: �迭�� ������� true, �Ⱥ������ false�� ����
		*/

		if (m_Length == 0)
			return true; //�����
		return false; //�Ⱥ����
	}

	void DisplayRecord()
	{
		for (int i = 0; i < m_Length; i++)
		{
			m_Array[i].DisplayRecordOnScreen();
		}
	}

	void DisplayRecord(SortedList<ItemType>& master)
	{
		for (int i = 0; i < m_Length; i++)
		{
			m_Array[i].DisplayRecordOnScreen(master);
		}


	}

	int GetLength()
	{
		/*
			precondition: m_Array�� ���ǵ��־���Ѵ�
			postcondition: m_Length�� ��ȯ�Ѵ�
		*/
		return m_Length;
	}


	int Add(T data)
	{
		/*
		precondition: m_Array�� ���ǵ��־���Ѵ�, data�� m_Array�� ����� �Ѵ�
		postcondition: �� �ڿ� data�� �߰��ϰ� �����ϸ� 1, �����ϸ� 0�� ��ȯ
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
			precondition: m_Array�� data�� �־�� �Ѵ�
			postcondition: m_Array���� data�� ��ġ�ϴ� ���� ã�� ����
						   �����ϸ� 1, �����ϸ� 0�� ��ȯ
		*/

		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i].CompareByName(data) == EQUAL)
			{
				m_Array[i] = m_Array[m_Length - 1];
				m_Length--;
				return 1;
			}
		}

		return 0;
	}

	void ResetList()
	{
		/*
			precondition: m_CurPointer�� ���ǵ��־�� �Ѵ�
			postcondition: m_CurPointer �� -1�� �����Ѵ�
		*/
		m_CurPointer = -1;
	}

	int Replace(T data)
	{
		/*
			precondition: m_Array�� data�� �־���Ѵ�.
			postcondition: �Էµ� data�� ������ ����� ã�� �ش� ����� data�� ġȯ�Ѵ�
						   �����ϸ� 1, �����ϸ� 0�� ��ȯ
		*/
		T tmp(data);

		if (Retrieve(data))
		{
			m_Array[m_CurPointer] = tmp;
			return 1;
		}
		return 0;
	}


	int Retrieve(T data)
	{
		/*
	precondition: T�� data�� �־�� ��
	postcondition: data�� ã���� �ش絥���Ϳ� ���� �����ϰ� 1, ��ã���� 0�� ����
		*/
		for (int i = 0; i < GetLength(); i++)
		{
			if (m_Array[i].CompareByName(data) == EQUAL)
			{
				//	data.SetRecord();
				data.DisplayRecordOnScreen();
				return 1;
			}
		}
		return 0;

	}

private:
	T* m_Array;  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
	//int MAXSIZE;
};

#endif	// _UNSORTEDLIST_H