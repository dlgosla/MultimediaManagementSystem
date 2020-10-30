#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include "ItemType.h"
#include "SortedList.h"

class AlbumType {

public:
	AlbumType()
	{
		name = ""; //콘텐츠 파일명
		album = ""; //앨범명
	}
	~AlbumType() {}

	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	string GetName() {
		return name;
	}

	/*
	precondition:  album가 정의돼 있어야 한다
	postcondition:  album를 리턴한다
	*/
	string GetAlbum() {
		return album;
	}

	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	void SetName(string inputName) 
	{
		name = inputName;
	}

	/*
	precondition: album가 정의돼 있어야 한다
	postcondition: album를 입력받은 값으로 바꾼다
	*/
	void SetAlbum(string inputAlbum) {
		album = inputAlbum;
	}

	/*
	precondition: name, kindOfContents, date, peoplem album가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	void SetRecord(string name, string album) {
		SetName(name);
		SetAlbum(album);
	}

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 출력한다
	*/
	void DisplayNameOnScreen()
	{
		cout << "콘텐츠 파일명: " << name << endl;
	}

	/*
	precondition: album가 정의돼 있어야한다
	postcondition:  album를 출력한다
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "앨범명: " << album << endl;
	}

	/*
	precondition: name, kindOfContents, date, peoplem album, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다 (자세한 정보)
	*/
	void DisplayRecordOnScreen(SortedList<ItemType>& master)
	{
		master.ResetList();
		ItemType item;
		item.SetName(name);
		master.Retrieve_SeqS(item);
		item.DisplayRecordOnScreen();
	}

	/*
	precondition: name, kindOfContents, date, peoplem album, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다 (간단한 정보)
	*/
	void DisplayRecordOnScreen()
	{
		cout << "앨범명: " << album << "컨텐츠 이름: " << name << endl;
	}

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 입력받는다
	*/
	void SetNameFromKB()
	{
		cout << "콘텐츠 파일명을 입력해주세요: ";
		cin >> name;
	}

	/*
	precondition: album가 정의돼 있어야한다
	postcondition: album를 입력받는다
	*/
	void SetAlbumFromKB()
	{
		cout << "앨범명을 입력해주세요: ";
		cin >> album;
	}

	/*
	precondition: 본문의 함수들이 정의돼 있어야한다
	postcondition: 함수들을 호출한다
	*/
	void SetRecordFromKB()
	{
		SetNameFromKB();
		SetAlbumFromKB();
	}

	bool operator>(AlbumType item)
	{
		return (this->GetName() > item.GetName());
	}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
	bool operator==(AlbumType item)
	{
		return (this->GetName() == item.GetName());
	}	//return 1 if this.id == data.id, 0 if not.

private:
	string name; //콘텐츠 파일명
	string album; //앨범명

};