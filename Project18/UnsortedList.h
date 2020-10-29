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
			postcondition: m_Array���� data�� ��ġ�ϴ� ���� ã�� ������ ��Ű�鼭 ����
						   �����ϸ� 1, �����ϸ� 0�� ��ȯ
		*/
		if (isEmpty())
			return 0;

		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i].CompareByName(data) == EQUAL)
			{
				for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
					m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
				m_Length--;	//������ ������ �ϳ� ����
				return 1;	//����(1)�� ����
			}
			return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����

		}
	}

	void ResetList()
	{
		/*
			precondition: m_CurPointer�� ���ǵ��־�� �Ѵ�
			postcondition: m_CurPointer �� -1�� �����Ѵ�
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