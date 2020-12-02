#pragma once
#include<iostream>
#include "SortedList.h"
#include "PeopleType.h"
#include "UnsortedList.h"
#include<string>
using namespace std;

/*
* 사람별로 저장
*/
class People {
private:
	string PeopleName; // 사람 이름
	int length; //사람 몇명인 지 저장
	UnsortedList<PeopleType> contentsList; // 특정 사람이 포함된 그룹들을 저장

public:
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 리스트 반환
	*/
	UnsortedList<PeopleType> getList();
	/*
	* pre: data가 정의돼 있어야함
	* post: 둘을 비교해서 less grater equal을 따짐
	*/
	RelationType CompareByName(const People& data);
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 컨텐츠에 대한 간단한정보출력
	*/
	void printRecord();
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 이 객체에대한 간단한정보출력
	*/
	void DisplayRecordOnScreen();

	People();
	~People();

	/*
	* pre:length가 정의 돼 있어야함
	* post: length 반환
	*/
	int getLength();

	/*
	* pre: item의 key와 일치하는 데이터가 있어야 함
	* post: item과 key가 일치하는 데이터 정보를 item으로 바꿈
	*/
	void replace(PeopleType item);

	/*
	* 연산자 오버로딩
	* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
	*/
	bool operator>(People item);
	/*
	* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
	*/
	bool operator==(People item);

	/*
		pre: PeopleName이 정의 돼 있어야 한다
		post: PeopleName을 리턴
	*/
	string getPeopleName();

	/*
	* post: 각 파라미터의 값을 멤버 변수에 저장함
	*/
	void setRecord(string e_name, int count = 0);
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 정보가 저장됨
	*/
	void printRecord(BinarySearchTree<ItemType>& master);
	/*
	* 모든 정보를 보여줌
	*/
	int Add(PeopleType e);  //people List에 콘텐츠 추가
	/*
	* pre:peopleList가 정의돼 있어야함, 동일한 key가 있으면 안됨
	* post: 성공시 1 반환
	*/
	int Delete(PeopleType e);  //people List에 콘텐츠 삭제
	/*
	* pre:peopleList가 정의돼 있어야함 삭제할 아이템의 key와 일치하는 key가 있어야함
	* post: 성공시 1 반환
	*/
	int Retrieve(PeopleType e);  //people List 콘텐츠 검색
	/*
	* pre:peopleList가 정의돼 있어야함
	* post: 성공시 1 , 실패시 0반환
	*/

};
