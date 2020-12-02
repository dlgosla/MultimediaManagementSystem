#pragma once
#include <iostream>
#include <fstream>	
#include <string>
#include "ItemType.h"
#include "BinarySearchTree.h"
using namespace std;

#include "ItemType.h"

#define MAXSIZE 10

template <typename T>
class SortedList
{
public:
	/*
		생성자
	*/
	SortedList();
	/*
		소멸자
	*/
	~SortedList();

	/*
	* pre: 없다
	* post: sortedList에 있는 레코드들을 출력
	*/
	void DisplayRecord();

	/*
	* pre: m_List 리스트가 있어야한다
	* post: 자세한 정보를 출력한다
	*/
	void DisplayRecord(BinarySearchTree<ItemType>& master);

	/*
	* pre: data와 일치하는 값이 m_Array에 있어야 한다
	* post: 성공시 1 실패시 0반환
	*/
	int Retrieve_SeqS(T& data);

	/*
	* pre: m_Array가 정의돼 있어야 한다
	* post: 이진검색 후 똑같은 걸 찾으면 data를 해당 값으로 변경하고 성공시 1 실패시 0 반환
	*/
	int Retrieve_BinaryS(T& data);

	/*
		precondition: m_Array가 정의돼 있어야함
		postcondition: 배열이 비었으면 true, 안비었으면 false를 리턴
	*/
	bool IsEmpty();

	/*
		precondition: m_Array에 data가 있어야 한다
		postcondition: m_Array에서 data와 일치하는 것을 찾아 삭제
					   성공하면 1, 실패하면 0을 반환
	*/
	int Delete(T data);

	/*
		precondition: m_Array에 data가 있어야한다.
		postcondition: 입력된 data와 동일한 기록을 찾아 해당 기록을 data로 치환한다
					   성공하면 1, 실패하면 0을 반환
	*/
	int Replace(T data);

	/*
		precondition: m_Array가 정의돼있어야한다
		postcondition: m_Length를 0으로 설정해서 빈리스트로 만든다
	*/
	void MakeEmpty();

	/*
		precondition: m_Array가 정의돼있어야한다
		postcondition: m_Length를 반환한다
	*/
	int GetLength();

	/*
		precondition: m_Array가 정의돼있어야한다
		postcondition: 꽉찼으면 true, 아니면 false를 리턴한다
	*/
	bool IsFull();

	/*
	precondition: m_Array가 정의돼있어야한다, data가 m_Array에 없어야 한다
	postcondition: 맨 뒤에 data를 추가하고 성공하면 1, 실패하면 0을 반환
	*/
	int Add(T data);

	/*
		precondition: m_CurPointer가 정의돼있어야 한다
		postcondition: m_CurPointer 를 -1로 설정한다
	*/
	void ResetList();

	/*
	precondition: m_Array가 정의돼 있어야 한다
	postcondition: data를 m_CurPointer위치에 저장하고 m_CurPointer를 반환, 실패시 -1반환
	*/
	int GetNextItem(T& data);

protected:
	T* m_Array;					/// 리스트 배열
	int m_Length;				/// 리스트의 길이
	int m_CurPointer;			/// 이터레이터 포인터

};

template <typename T>
SortedList<T>::SortedList()
{
	m_Array = new T[MAXSIZE];
	m_Length = 0;
	m_CurPointer = 0;
}

template <typename T>
SortedList<T>::~SortedList() { delete[] m_Array; }

template <typename T>
void SortedList<T>::DisplayRecord()
{
	for (int i = 0; i < m_Length; i++)
	{
		m_Array[i].DisplayRecordOnScreen();
	}

}
template <typename T>
void SortedList<T>::DisplayRecord(BinarySearchTree<ItemType>& master)
{
	for (int i = 0; i < m_Length; i++)
	{
		m_Array[i].DisplayRecordOnScreen(master);
	}
}


template <typename T>
int SortedList<T>::Retrieve_SeqS(T& data)
{
	/*
	* pre: data와 일치하는 값이 m_Array에 있어야 한다
	* post: 성공시 1 실패시 0반환
	*/
	T CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		switch (CurItem.CompareByName(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 Primary key가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 Primary key가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}

template <typename T>
int SortedList<T>::Retrieve_BinaryS(T& data)
{
	/*
	* pre: m_Array가 정의돼 있어야 한다
	* post: 이진검색 후 똑같은 걸 찾으면 data를 해당 값으로 변경하고 성공시 1 실패시 0 반환
	*/
	T CurItem;

	if (m_Length == 0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos = m_Length / 2;	//배열의 중간부터 시작
	while (1)
	{
		switch (m_Array[currentPos].CompareByName(data))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 Primary key가 일치한다면
			data = m_Array[currentPos];	//data에 발견한 값을 리턴
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 Primary key가 입력 아이템의 Primary key보다 크다면
			if (currentPos == 0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos /= 2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 Primary key가 입력 아이템의 Primary key보다 작다면
			if (currentPos == m_Length - 1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos = (currentPos + m_Length) / 2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}

template <typename T>
bool SortedList<T>::IsEmpty()
{
	/*
		precondition: m_Array가 정의돼 있어야함
		postcondition: 배열이 비었으면 true, 안비었으면 false를 리턴
	*/

	if (m_Length == 0)
		return true; //비었음
	return false; //안비었음
}

template <typename T>
int SortedList<T>::Delete(T data)
{
	/*
		precondition: m_Array에 data가 있어야 한다
		postcondition: m_Array에서 data와 일치하는 것을 찾아 삭제
					   성공하면 1, 실패하면 0을 반환
	*/
	if (IsEmpty())
		return 0;

	if (Retrieve_SeqS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}

	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

template <typename T>
int SortedList<T>::Replace(T data)
{
	/*
		precondition: m_Array에 data가 있어야한다.
		postcondition: 입력된 data와 동일한 기록을 찾아 해당 기록을 data로 치환한다
					   성공하면 1, 실패하면 0을 반환
	*/
	T tmp(data);

	if (Retrieve_SeqS(data))
	{
		m_Array[m_CurPointer] = tmp;
		return 1;
	}

	return 0;
}


template <typename T>
void SortedList<T>::MakeEmpty()
{
	/*
		precondition: m_Array가 정의돼있어야한다
		postcondition: m_Length를 0으로 설정해서 빈리스트로 만든다
	*/
	m_Length = 0; //리스트에 저장된 레코드 수
}

template <typename T>
int SortedList<T>::GetLength()
{
	/*
		precondition: m_Array가 정의돼있어야한다
		postcondition: m_Length를 반환한다
	*/
	return m_Length;
}

template <typename T>
bool SortedList<T>::IsFull()
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

template <typename T>
int SortedList<T>::Add(T data)
{
	/*
	precondition: m_Array가 정의돼있어야한다, data가 m_Array에 없어야 한다
	postcondition: 맨 뒤에 data를 추가하고 성공하면 1, 실패하면 0을 반환
	*/

	if (IsFull()) return 0;
	if (m_Length == 0) {
		m_Array[m_Length++] = data;
		return 1;
	}

	int iPos = 0;
	bool found = false;
	T curItem;
	ResetList();
	iPos = GetNextItem(curItem);

	while (iPos > -1 && !found)
	{
		switch (curItem.CompareByName(data))
		{
		case EQUAL:
			cout << " %%% 데이터는 중복될 수 없습니다 %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos = GetNextItem(curItem);
			break;
		}
	}

	if (iPos == -1) {
		m_Array[m_Length++] = data;
		return 1;
	}

	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}

	m_Array[iPos] = data;

	m_Length++;
	return 1;

}

template <typename T>
void SortedList<T>::ResetList()
{
	/*
		precondition: m_CurPointer가 정의돼있어야 한다
		postcondition: m_CurPointer 를 -1로 설정한다
	*/
	m_CurPointer = -1;
}

template <typename T>
int SortedList<T>::GetNextItem(T& data)
{
	/*
	precondition: m_Array가 정의돼 있어야 한다
	postcondition: data를 m_CurPointer위치에 저장하고 m_CurPointer를 반환, 실패시 -1반환
	*/
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}
