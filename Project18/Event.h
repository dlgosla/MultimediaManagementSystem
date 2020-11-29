#pragma once
#include<iostream>
#include "SortedList.h"
#include "EventType.h"
#include "UnsortedList.h"
#include<string>
using namespace std;


class Event {
private:
	string eventName; // 이벤트 이름
	string description; //이벤트 설명
	int countOfEvent; //이벤트 개수
	UnsortedList<EventType> contentsList;

public:
	Event();
	~Event();

	/*
	* post: 리스트 리턴
	*/
	UnsortedList<EventType> getList();

	/*
	* pre:countOfEvent가 정의 돼 있어야함
	* post: countOfEvent 반환
	*/
	int getCountOfEvent();

	/*
	* pre: item의 key와 일치하는 데이터가 있어야 함
	* post: item과 key가 일치하는 데이터 정보를 item으로 바꿈
	*/
	void replace(EventType item);

	/*
	* 연산자 오버로딩
	* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
	*/
	bool operator>(Event item);
	/*
	* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
	*/
	bool operator==(Event item);

	/*
		pre: eventName이 정의 돼 있어야 한다
		post: eventName을 리턴
	*/
	string getEventName();

	/*
	* post: 각 파라미터의 값을 멤버 변수에 저장함
	*/
	void setRecord(string e_name, string desc = "", int count = 0);
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 정보가 저장됨
	*/
	void printRecord(SortedList<ItemType>& master);
	/*
	* 모든 정보를 보여줌
	*/
	int Add(EventType e);  //eventList에 콘텐츠 추가
	/*
	* pre:eventList가 정의돼 있어야함
	* post: 성공시 1 반환
	*/
	int Delete(EventType eName);  //eventList에 콘텐츠 삭제
	/*
	* pre:eventList가 정의돼 있어야함
	* post: 성공시 1 반환
	*/
	int Retrieve(EventType e);  //eventList 콘텐츠 검색
	/*
	* pre:eventList가 정의돼 있어야함
	* post: 성공시 1 , 실패시 0반환
	*/

};
