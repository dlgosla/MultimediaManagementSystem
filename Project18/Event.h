#include<iostream>
#include "SortedList.h"
#include "EventType.h"
#include "UnsortedList.h"
using namespace std;

class Event {
private:
	string eventName; //이벤트 이름
	string description; //이벤트 설명
	int countOfEvent; //이벤트 개수
	SortedList<EventType> eventList; // 이벤트리스트

public:
	Event() {
		eventName = "";
		description = "";
		countOfEvent = 0;
	}
	void setRecord(string e_name, string desc, int count);
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 정보가 저장됨
	*/
	void printRecord();
	/*
	* 모든 정보를 보여줌
	*/
	int Add();  //eventList에 콘텐츠 추가
	/*
	* pre:eventList가 정의돼 있어야함
	* post: 성공시 1 반환
	*/
	int Delete();  //eventList에 콘텐츠 삭제
	/*
	* pre:eventList가 정의돼 있어야함
	* post: 성공시 1 반환
	*/
	int Retrieve();  //eventList 콘텐츠 검색
	/*
	* pre:eventList가 정의돼 있어야함
	* post: 성공시 1 , 실패시 0반환
	*/

};
