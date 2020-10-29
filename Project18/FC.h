#pragma once
#include<iostream>
#include<string>
using namespace std;

class FC {
private:
	string fileName; //콘텐츠 파일의 이름
	//string memo; //콘텐츠 파일의 설명
	int countOfView; //이 컨텐츠를 본 횟수

public:
	void DisplayRecordOnScreen(); //정보를 출력함
	/*
	* pre: FC의 멤버변수가 정의돼 있어야함
	* post: 정보를 출력하고 아무것도 반환하지 않음
	*/
	void setRecord(string fileName, int countOfView = 0);//정보를 입력함
	/*
	* pre:딱히 없음
	* post: 정보를 저장하고 아무것도 반환하지 않음
	*/
	string getFileName(); //fileName을 반환
	/*
	* pre:fileName이 정의돼 있어야함
	* post: fileName을 반환
	*/
	void view();
	/*
	* pre: countOfView가 정의돼 있어한다
	* post: countOfView를 한번 늘린다.
	*/
	int CompareByName(const FC& data);
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less(0), grater(1), equal(2)을 반환한다
	*/
	int getCountOfView();

	


};