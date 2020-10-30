#pragma once
#include<iostream>
#include "SortedList.h"
#include "AlbumType.h"
#include "UnsortedList.h"
#include "AlbumType.h"
#include<string>
using namespace std;


class Album {
private:
	string albumName; // �ٹ� �̸�
	string description; //�ٹ� ����
	int countOfAlbum; //�ٹ� ����
	UnsortedList<AlbumType> contentsList;

public:
	Album()
	{
		albumName = "";
		description = "";
		countOfAlbum = 0;
		contentsList.ResetList();
	}
	~Album()
	{}

	/*
	* pre:countOfAlbum�� ���� �� �־����
	* post: countOfAlbum ��ȯ
	*/
	int getCountOfAlbum()
	{
		//re
	}

	/*
	* pre: item�� key�� ��ġ�ϴ� �����Ͱ� �־�� ��
	* post: item�� key�� ��ġ�ϴ� ������ ������ item���� �ٲ�
	*/
	void replace(AlbumType item);

	/*
	* ������ �����ε�
	* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
	*/
	bool operator>(Album item);
	/*
	* post: �� ���� key���� ������ true �ƴϸ� false�� ����
	*/
	bool operator==(Album item);

	/*
		pre: albumName�� ���� �� �־�� �Ѵ�
		post: albumName�� ����
	*/
	string getAlbumName();

	/*
	* post: �� �Ķ������ ���� ��� ������ ������
	*/
	void setRecord(string e_name, string desc = "", int count = 0);
	/*
	* pre: �� ��������� ���ǵ� �־����
	* post: ������ �����
	*/
	void printRecord(SortedList<ItemType>& master);
	/*
	* ��� ������ ������
	*/
	int Add(AlbumType e);  //albumList�� ������ �߰�
	/*
	* pre:albumList�� ���ǵ� �־����
	* post: ������ 1 ��ȯ
	*/
	int Delete(AlbumType eName);  //albumList�� ������ ����
	/*
	* pre:albumList�� ���ǵ� �־����
	* post: ������ 1 ��ȯ
	*/
	int Retrieve(AlbumType e);  //albumList ������ �˻�
	/*
	* pre:albumList�� ���ǵ� �־����
	* post: ������ 1 , ���н� 0��ȯ
	*/

};
