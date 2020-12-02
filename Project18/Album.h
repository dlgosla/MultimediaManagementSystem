#pragma once
#include<iostream>
#include "SortedList.h"
#include "AlbumType.h"
#include "UnsortedList.h"
#include<string>
using namespace std;


class Album {
private:
	string albumName; // �ٹ� �̸�
	string description; //�ٹ� ����
	int countOfAlbum; //�ٹ� ����
	UnsortedList<AlbumType> contentsList;

public:
	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	RelationType CompareByName(const Album& data);



	/*
	������
	*/
	Album();

	/*
	�Ҹ���
	*/
	~Album();

	/*
	* pre:countOfAlbum�� ���� �� �־����
	* post: countOfAlbum ��ȯ
	*/
	int getCountOfAlbum();

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

	/*
	* post: ������ ���� ���
	*/
	void printRecord();

	/*
	* ��� ������ ������
	*/
	void printRecord(BinarySearchTree<ItemType>& master);


	/*
	* pre:albumList�� ���ǵ� �־����
	* post: �߰� �ϰ� ������ 1, ���н� 0 ��ȯ
	*/
	int Add(AlbumType a);  //albumList�� ������ �߰�


	/*
	* pre:albumList�� ���ǵ� �־����
	* post: �����ϰ� ������ 1, ���н� 0 ��ȯ
	*/
	int Delete(AlbumType aName);  //albumList�� ������ ����

	/*
	* pre:albumList�� ���ǵ� �־����
	* post: a�� ã�Ƽ� ��ȯ�ϰ� ���� 1 ���� 0 ��ȯ
	*/
	int Retrieve(AlbumType item);  //albumList ������ �˻�

	/*
	*
	* post: �� �ٹ��� ���� ������ ���� ���
	*/
	void DisplayRecordOnScreen();




};
