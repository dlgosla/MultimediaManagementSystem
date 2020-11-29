#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

//한 콘텐츠의 전체정보를 저장하는 클래스
class ItemType {

public:
	/*
	* 연산자 오버로딩
	* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
	*/
	bool operator>(ItemType item);

	/*
	* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
	*/
	bool operator==(ItemType item);

	/*
	* 생성자
	*/
	ItemType();

	/*
	* 소멸자
	*/
	~ItemType();

	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	string GetName();

	/*
	precondition: kindOfContents가 정의돼 있어야 한다
	postcondition: kindOfContents를 리턴한다
	*/
	int GetkindOfContents();
	/*
	precondition: date가 정의돼 있어야 한다
	postcondition: date를 리턴한다
	*/
	string GetDate();

	/*
	precondition: people이 정의돼 있어야 한다
	postcondition: people을 리턴한다
	*/
	string GetPeople();

	/*
	precondition:  event가 정의돼 있어야 한다
	postcondition:  event를 리턴한다
	*/
	string GetEvent();

	/*
	precondition:  classification가 정의돼 있어야 한다
	postcondition:  classification를 리턴한다
	*/
	int GetClassification();

	/*
	precondition:  memo가 정의돼 있어야 한다
	postcondition:  memo를 리턴한다
	*/
	string GetMemo();

	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	void SetName(string inputName);

	/*
	precondition: kindOfContents가 정의돼 있어야 한다
	postcondition: kindOfContents를 입력받은 값으로 바꾼다
	*/
	void SetkindOfContents(int inputKindOfContent);

	/*
precondition: date가 정의돼 있어야 한다
postcondition: date를 입력받은 값으로 바꾼다
*/
	void SetDate(string inputDate);

	/*
	precondition:  people이 정의돼 있어야 한다
	postcondition: people을 입력받은 값으로 바꾼다
	*/
	void SetPeople(string inputPeople);

	/*
	precondition: event가 정의돼 있어야 한다
	postcondition: event를 입력받은 값으로 바꾼다
	*/
	void SetEvent(string inputEvent);

	/*
	precondition: classification가 정의돼 있어야 한다
	postcondition: classification를 입력받은 값으로 바꾼다
	*/
	void SetClassification(int inputClassification);

	/*
	precondition: memo가 정의돼 있어야 한다
	postcondition: memo를 입력받은 값으로 바꾼다
	*/
	void setMemo(string inputMemo);

	/*
	precondition: name, kindOfContents, date, peoplem event가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	void SetRecord(string name, int kindOfContents, string data, string people, string event, int  inputClassification, string inputMeno);

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 출력한다
	*/
	void DisplayNameOnScreen();

	/*
	precondition: kindOfContents가 정의돼 있어야한다
	postcondition: kindOfContents를 출력한다
	*/
	void DisplayKindOnScreen();

	/*
	precondition: date가 정의돼 있어야한다
	postcondition: date를 출력한다
	*/
	void DisplayDateOnScreen();

	/*
	precondition: people이 정의돼 있어야한다
	postcondition: people을 출력한다
	*/
	void DisplayPeopleOnScreen();

	/*
	precondition: event가 정의돼 있어야한다
	postcondition:  event를 출력한다
	*/
	void DisplayEventOnScreen();

	/*
precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
postcondition: 각 요소를 출력한다
*/
	void DisplayRecordOnScreen();

	/*
	precondition: classification가 정의돼 있어야한다
	postcondition: classification를 입력받는다
	*/
	void DisplayClassificationOnScreen();

	/*
	precondition: memo가 정의돼 있어야한다
	postcondition:  memo를 출력한다
	*/
	void DisplayMemoOnScreen();

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 입력받는다
	*/
	void SetNameFromKB();

	/*
	precondition: kindOfContents가 정의돼 있어야한다
	postcondition: kindOfContents를 입력받는다
	*/
	void SetKindFromKB();

	/*
	precondition: date가 정의돼 있어야한다
	postcondition: date를 입력받는다
	*/
	void SetDateFromKB();

	/*
	precondition: people이 정의돼 있어야한다
	postcondition: people을 입력받는다
	*/
	void SetPeopleFromKB();

	/*
	precondition: event가 정의돼 있어야한다
	postcondition: event를 입력받는다
	*/
	void SetEventFromKB();

	/*
precondition: 본문의 함수들이 정의돼 있어야한다
postcondition: 함수들을 호출한다
*/
	void SetRecordFromKB();

	/*
	precondition: classification가 정의돼 있어야한다
	postcondition: classification를 입력받는다
	*/
	void SetClassificationFromKB();

	/*
	precondition: memo가 정의돼 있어야한다
	postcondition: memo를 입력받는다
	*/
	void SetMemoFromKB();

	/*
	precondition: fin이 정의돼 있어야한다
	postcondition: 파일에서 읽어오고 성공하면 1을 리턴한다
	*/
	int ReadDataFromFile(ifstream& fin);// 학생정보를파일에서읽는함수

	/*
	precondition: fout이 정의돼 있어야 한다
	postcondition: 각 변수들을 파일에 저장하고 성공하면 1을 리턴한다
	*/
	int WriteDataToFile(ofstream& fout);// 학생정보를파일로출력하는함수

	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	RelationType CompareByName(const ItemType& data);// primary key (ID)를기준으로학생정보를비교하는함수

private:
	string name; //콘텐츠 파일명
	int kindOfContents; //콘텐츠 종류 (1=사진 2=동영상..)
	string date; //생성날짜와 시간
	string people; //콘텐츠에 포함된 사람
	string event; //이벤트명
	int classification; // 콘텐츠의 구분 (인물 장소 ..)
	string memo; //콘텐츠 내용


};