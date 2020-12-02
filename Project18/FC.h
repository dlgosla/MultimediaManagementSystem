#pragma once
#include "SortedList.h"

//즐겨찾는 콘텐츠 클래스
class FC {
private:
	string fileName; //콘텐츠 파일의 이름
	int countOfView; //이 컨텐츠를 본 횟수

public:
	void DisplayRecordOnScreen(BinarySearchTree<ItemType>& master)
	{
		/*
		precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
		postcondition: 각 요소를 출력한다
		*/
		//master.ResetList();
		ItemType item;
		item.SetName(fileName);
		bool found = false;
		master.RetrieveItem(item,found);
		item.DisplayRecordOnScreen();
	}


	/*
	* pre: FC의 멤버변수가 정의돼 있어야함
	* post: 정보를 출력하고 아무것도 반환하지 않음
	*/
	void DisplayRecordOnScreen(); //정보를 출력함

	/*
	* pre:딱히 없음
	* post: 정보를 저장하고 아무것도 반환하지 않음
	*/
	void setRecord(string fileName, int countOfView = 0);//정보를 입력함

	/*
	* pre:fileName이 정의돼 있어야함
	* post: fileName을 반환
	*/
	string getFileName(); //fileName을 반환

	/*
	* pre: countOfView가 정의돼 있어한다
	* post: countOfView를 한번 늘린다.
	*/
	void view(); // 콘텐츠의 이름을 입력받아서 해당 콘텐츠의 view를 1증가 시킴

	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less(0), grater(1), equal(2)을 반환한다
	*/
	int CompareByName(const FC& data);  //name을 기준으로 두 데이터를 비교

	/*
	precondition: countOfView가 정의돼 있어야한다
	postcondition: countOfView를 리턴한다
	*/
	int getCountOfView();


};