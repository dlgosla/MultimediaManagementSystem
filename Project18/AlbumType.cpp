#include "AlbumType.h"

AlbumType::AlbumType()
{
	name = ""; //콘텐츠 파일명
	album = ""; //앨범명
}
AlbumType::~AlbumType()
{

}

void AlbumType::DisplayRecordOnScreen(SortedList<ItemType>& master)
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo가 정의돼 있어야한다
	postcondition: 각 요소를 출력한다
	*/
	master.ResetList();
	ItemType item;
	item.SetName(name);
	master.Retrieve_SeqS(item);
	item.DisplayRecordOnScreen();
}

void AlbumType::DisplayRecordOnScreen()
{
	/*
	postcondition: 출력한다
	*/

	cout << " 컨텐츠 이름: " << name << endl;
}

/*
precondition: name이 정의돼 있어야 한다
postcondition: name을 리턴한다
*/
string AlbumType::GetName() {
	return name;
}

/*
precondition:  album가 정의돼 있어야 한다
postcondition:  album를 리턴한다
*/
string AlbumType::GetAlbum() {
	return album;
}

/*
precondition:  name이 정의돼 있어야 한다
postcondition: name을 입력받은 값으로 바꾼다
*/
void AlbumType::SetName(string inputName)
{
	name = inputName;
}

/*
precondition: album가 정의돼 있어야 한다
postcondition: album를 입력받은 값으로 바꾼다
*/
void AlbumType::SetAlbum(string inputAlbum)
{
	album = inputAlbum;
}
/*
precondition: name, kindOfContents, date, peoplem album가 정의 돼 있어야 한다
postcondition: 각 변수를 입력받은 값으로 바꾼다
*/
void AlbumType::SetRecord(string name, string album)
{
	SetName(name);
	SetAlbum(album);
}

/*
precondition: name이 정의돼 있어야한다
postcondition: name을 출력한다
*/
void AlbumType::DisplayNameOnScreen()
{
	cout << "콘텐츠 파일명: " << name << endl;
}

/*
precondition: album가 정의돼 있어야한다
postcondition:  album를 출력한다
*/
void AlbumType::DisplayAlbumOnScreen()
{
	cout << "앨범명: " << album << endl;
}

/*
precondition: name, kindOfContents, date, peoplem album, classification, memo가 정의돼 있어야한다
postcondition: 각 요소를 출력한다
*/
void AlbumType::DisplayRecord()
{
	cout << "콘텐츠 파일명: " << name << "앨범명: " << album << endl;
}

/*
precondition: name, kindOfContents, date, peoplem album, classification, memo가 정의돼 있어야한다
postcondition: 각 요소를 출력한다
*/
//void DisplayRecordOnScreen(SortedList<ItemType>& master);

/*
precondition: name이 정의돼 있어야한다
postcondition: name을 입력받는다
*/
void AlbumType::SetNameFromKB()
{
	cout << "콘텐츠 파일명을 입력해주세요: ";
	cin >> name;

}

/*
precondition: album가 정의돼 있어야한다
postcondition: album를 입력받는다
*/
void AlbumType::SetAlbumFromKB()
{
	cout << "앨범명을 입력해주세요: ";
	cin >> album;
}

/*
precondition: 본문의 함수들이 정의돼 있어야한다
postcondition: 함수들을 호출한다
*/
void AlbumType::SetRecordFromKB()
{
	SetNameFromKB();
	SetAlbumFromKB();
}

bool AlbumType::operator>(AlbumType item)
{
	return (this->GetName() > item.GetName());
}


bool AlbumType::operator==(AlbumType item)
{
	return (this->GetName() == item.GetName());
}

RelationType AlbumType::CompareByName(const AlbumType& data)
{
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	if (data.name > name)
		return LESS;

	else if (data.name < name)
		return GREATER;
	else
		return EQUAL;

}