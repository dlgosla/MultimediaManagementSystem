#include "SortedList.h"

class AlbumType {

public:
	AlbumType();
	~AlbumType();

	/*
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	string GetName();

	/*
	precondition:  album�� ���ǵ� �־�� �Ѵ�
	postcondition:  album�� �����Ѵ�
	*/
	string GetAlbum();

	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	void SetName(string inputName);

	/*
	precondition: album�� ���ǵ� �־�� �Ѵ�
	postcondition: album�� �Է¹��� ������ �ٲ۴�
	*/
	void SetAlbum(string inputAlbum);

	/*
	precondition: name, kindOfContents, date, peoplem album�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	void SetRecord(string name, string album = "");

	/*
	* ������ �����ε�
	* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
	*/
	bool operator>(AlbumType item);

	/*
	* post: �� ���� key���� ������ true �ƴϸ� false�� ����
	*/
	bool operator==(AlbumType item);

	/*
	* post: �������� ���� ������ ���� ���
	*/
	void DisplayRecord();


	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� ����Ѵ�
	*/
	void DisplayNameOnScreen();

	/*
	precondition: album�� ���ǵ� �־���Ѵ�
	postcondition:  album�� ����Ѵ�
	*/
	void DisplayAlbumOnScreen();

	/*
	* pre: m_List����Ʈ�� �����ؾ��Ѵ�
	postcondition: �������� ���� �ڼ��� ��� ���
	*/
	void DisplayRecordOnScreen(SortedList<ItemType>& master);

	/*
	postcondition: �� ��Ҹ� ����Ѵ�
	*/
	void DisplayRecordOnScreen();

	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� �Է¹޴´�
	*/
	void SetNameFromKB();

	/*
	precondition: album�� ���ǵ� �־���Ѵ�
	postcondition: album�� �Է¹޴´�
	*/
	void SetAlbumFromKB();

	/*
	precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
	postcondition: �Լ����� ȣ���Ѵ�
	*/
	void SetRecordFromKB();


	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	RelationType CompareByName(const AlbumType& data);// primary key (ID)�������������������������ϴ��Լ�


private:
	string name; //������ ���ϸ�
	string album; //�ٹ���

};

