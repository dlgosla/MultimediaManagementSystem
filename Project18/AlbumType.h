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
		name = ""; //������ ���ϸ�
		album = ""; //�ٹ���
	}
	~AlbumType() {}

	/*
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	string GetName() {
		return name;
	}

	/*
	precondition:  album�� ���ǵ� �־�� �Ѵ�
	postcondition:  album�� �����Ѵ�
	*/
	string GetAlbum() {
		return album;
	}

	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	void SetName(string inputName) 
	{
		name = inputName;
	}

	/*
	precondition: album�� ���ǵ� �־�� �Ѵ�
	postcondition: album�� �Է¹��� ������ �ٲ۴�
	*/
	void SetAlbum(string inputAlbum) {
		album = inputAlbum;
	}

	/*
	precondition: name, kindOfContents, date, peoplem album�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	void SetRecord(string name, string album) {
		SetName(name);
		SetAlbum(album);
	}

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� ����Ѵ�
	*/
	void DisplayNameOnScreen()
	{
		cout << "������ ���ϸ�: " << name << endl;
	}

	/*
	precondition: album�� ���ǵ� �־���Ѵ�
	postcondition:  album�� ����Ѵ�
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "�ٹ���: " << album << endl;
	}

	/*
	precondition: name, kindOfContents, date, peoplem album, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ� (�ڼ��� ����)
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
	precondition: name, kindOfContents, date, peoplem album, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ� (������ ����)
	*/
	void DisplayRecordOnScreen()
	{
		cout << "�ٹ���: " << album << "������ �̸�: " << name << endl;
	}

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� �Է¹޴´�
	*/
	void SetNameFromKB()
	{
		cout << "������ ���ϸ��� �Է����ּ���: ";
		cin >> name;
	}

	/*
	precondition: album�� ���ǵ� �־���Ѵ�
	postcondition: album�� �Է¹޴´�
	*/
	void SetAlbumFromKB()
	{
		cout << "�ٹ����� �Է����ּ���: ";
		cin >> album;
	}

	/*
	precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
	postcondition: �Լ����� ȣ���Ѵ�
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
	string name; //������ ���ϸ�
	string album; //�ٹ���

};