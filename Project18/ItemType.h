#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
class ItemType {

public:
	ItemType()
	{
		name = ""; //콘텐츠 파일명
		kindOfContents = -1; //콘텐츠 종류
		date = ""; //생성날짜와 시간
		people = ""; //콘텐츠에 포함된 사람
		event = ""; //이벤트명
	}
	~ItemType() {}
	string GetName();
	int GetkindOfContents();
	string GetDate();
	string GetPeople();
	string GetEvent();
	int GetClassification();
	string GetMemo();

	void SetName(string inputName);
	void SetkindOfContents(int inputKindOfContent);
	void SetDate(string inputDate);
	void SetPeople(string inputPeople);
	void SetEvent(string inputEvent);
	void SetClassification(int inputClassification);
	void setMemo(string inputMemo);
	void SetRecord(string name, int kindOfContents, string data, string people, string event, int  inputClassification, string inputMeno);

	void DisplayNameOnScreen();
	void DisplayKindOnScreen();
	void DisplayDateOnScreen();
	void DisplayPeopleOnScreen();
	void DisplayEventOnScreen();
	void DisplayRecordOnScreen();
	void DisplayClassificationOnScreen();
	void DisplayMemoOnScreen();

	void SetNameFromKB();
	void SetKindFromKB();
	void SetDateFromKB();
	void SetPeopleFromKB();
	void SetEventFromKB();
	void SetRecordFromKB();// 키보드로학생정보입력함수
	void SetClassificationFromKB();
	void SetMemoFromKB();

	int ReadDataFromFile(ifstream& fin);// 학생정보를파일에서읽는함수
	int WriteDataToFile(ofstream& fout);// 학생정보를파일로출력하는함수
	RelationType CompareByName(const ItemType& data);// primary key (ID)를기준으로학생정보를비교하는함수

private:
	string name; //콘텐츠 파일명
	int kindOfContents; //콘텐츠 종류 (사진 동영상..)
	string date; //생성날짜와 시간
	string people; //콘텐츠에 포함된 사람
	string event; //이벤트명
	int classification; // 콘텐츠의 구분 (인물 장소 ..)
	string memo; //콘텐츠 내용
	

};