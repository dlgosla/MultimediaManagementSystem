#include "SortedList.h"

class AlbumType {

public:
	AlbumType();
	~AlbumType();

	/*
	precondition: name이 정의돼 있어야 한다
	postcondition: name을 리턴한다
	*/
	string GetName();

	/*
	precondition:  album가 정의돼 있어야 한다
	postcondition:  album를 리턴한다
	*/
	string GetAlbum();

	/*
	precondition:  name이 정의돼 있어야 한다
	postcondition: name을 입력받은 값으로 바꾼다
	*/
	void SetName(string inputName);

	/*
	precondition: album가 정의돼 있어야 한다
	postcondition: album를 입력받은 값으로 바꾼다
	*/
	void SetAlbum(string inputAlbum);

	/*
	precondition: name, kindOfContents, date, peoplem album가 정의 돼 있어야 한다
	postcondition: 각 변수를 입력받은 값으로 바꾼다
	*/
	void SetRecord(string name, string album = "");

	/*
	* 연산자 오버로딩
	* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
	*/
	bool operator>(AlbumType item);

	/*
	* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
	*/
	bool operator==(AlbumType item);

	/*
	* post: 컨텐츠에 관한 간단한 정보 출력
	*/
	void DisplayRecord();


	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 출력한다
	*/
	void DisplayNameOnScreen();

	/*
	precondition: album가 정의돼 있어야한다
	postcondition:  album를 출력한다
	*/
	void DisplayAlbumOnScreen();

	/*
	* pre: m_List리스트가 존재해야한다
	postcondition: 컨텐츠에 곤한 자세한 요소 출력
	*/
	void DisplayRecordOnScreen(SortedList<ItemType>& master);

	/*
	postcondition: 각 요소를 출력한다
	*/
	void DisplayRecordOnScreen();

	/*
	precondition: name이 정의돼 있어야한다
	postcondition: name을 입력받는다
	*/
	void SetNameFromKB();

	/*
	precondition: album가 정의돼 있어야한다
	postcondition: album를 입력받는다
	*/
	void SetAlbumFromKB();

	/*
	precondition: 본문의 함수들이 정의돼 있어야한다
	postcondition: 함수들을 호출한다
	*/
	void SetRecordFromKB();


	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	RelationType CompareByName(const AlbumType& data);// primary key (ID)를기준으로콘텐츠정보를비교하는함수


private:
	string name; //콘텐츠 파일명
	string album; //앨범명

};

