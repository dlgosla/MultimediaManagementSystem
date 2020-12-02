#pragma once
#include<iostream>
#include "SortedList.h"
#include "AlbumType.h"
#include "UnsortedList.h"
#include<string>
using namespace std;


class Album {
private:
	string albumName; // 앨범 이름
	string description; //앨범 설명
	int countOfAlbum; //앨범 개수
	UnsortedList<AlbumType> contentsList;

public:
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	RelationType CompareByName(const Album& data);



	/*
	생성자
	*/
	Album();

	/*
	소멸자
	*/
	~Album();

	/*
	* pre:countOfAlbum가 정의 돼 있어야함
	* post: countOfAlbum 반환
	*/
	int getCountOfAlbum();

	/*
	* pre: item의 key와 일치하는 데이터가 있어야 함
	* post: item과 key가 일치하는 데이터 정보를 item으로 바꿈
	*/
	void replace(AlbumType item);

	/*
	* 연산자 오버로딩
	* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
	*/
	bool operator>(Album item);
	/*
	* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
	*/
	bool operator==(Album item);

	/*
		pre: albumName이 정의 돼 있어야 한다
		post: albumName을 리턴
	*/
	string getAlbumName();

	/*
	* post: 각 파라미터의 값을 멤버 변수에 저장함
	*/
	void setRecord(string e_name, string desc = "", int count = 0);
	/*
	* pre: 각 멤버변수가 정의돼 있어야함
	* post: 정보가 저장됨
	*/

	/*
	* post: 간단한 정보 출력
	*/
	void printRecord();

	/*
	* 모든 정보를 보여줌
	*/
	void printRecord(BinarySearchTree<ItemType>& master);


	/*
	* pre:albumList가 정의돼 있어야함
	* post: 추가 하고 성공시 1, 실패시 0 반환
	*/
	int Add(AlbumType a);  //albumList에 콘텐츠 추가


	/*
	* pre:albumList가 정의돼 있어야함
	* post: 삭제하고 성공시 1, 실패시 0 반환
	*/
	int Delete(AlbumType aName);  //albumList에 콘텐츠 삭제

	/*
	* pre:albumList가 정의돼 있어야함
	* post: a를 찾아서 반환하고 성공 1 실패 0 반환
	*/
	int Retrieve(AlbumType item);  //albumList 콘텐츠 검색

	/*
	*
	* post: 이 앨범에 관한 간단한 정보 출력
	*/
	void DisplayRecordOnScreen();




};
