#include "Album.h"

RelationType Album::CompareByName(const Album& data)
{
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
	*/
	if (data.albumName > albumName)
		return LESS;

	else if (data.albumName < albumName)
		return GREATER;
	else
		return EQUAL;

}

Album::Album()
{
	albumName = "";
	description = "";
	countOfAlbum = 0;
	contentsList.ResetList();
}
Album::~Album()
{

}

/*
* pre:countOfAlbum가 정의 돼 있어야함
* post: countOfAlbum 반환
*/
int Album::getCountOfAlbum()
{
	return countOfAlbum;
}

/*
* pre: item의 key와 일치하는 데이터가 있어야 함
* post: item과 key가 일치하는 데이터 정보를 item으로 바꿈
*/
void Album::replace(AlbumType item)
{
	contentsList.Replace(item);
}

/*
* 연산자 오버로딩
* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
*/
bool Album::operator>(Album item)
{
	return this->albumName > item.getAlbumName();
}
/*
* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
*/
bool Album::operator==(Album item)
{
	return this->albumName == item.getAlbumName();
}

/*
	pre: albumName이 정의 돼 있어야 한다
	post: albumName을 리턴
*/
string Album::getAlbumName()
{
	return albumName;
}

/*
* post: 각 파라미터의 값을 멤버 변수에 저장함
*/
void Album::setRecord(string e_name, string desc, int count)
{
	albumName = e_name;
	description = desc;
	countOfAlbum = count;
}
/*
* pre: 각 멤버변수가 정의돼 있어야함
* post: 자세한 정보를 출력
*/
void Album::printRecord(SortedList<ItemType>& master) {
	contentsList.DisplayRecord(master);
}

void Album::printRecord() {
	contentsList.DisplayRecord();
}

/*
* 간단한 정보를 보여줌
*/
void Album::DisplayRecordOnScreen() {
	cout << "앨범명: " << albumName << " 앨범설명: " << description << " 컨텐츠 수: " << countOfAlbum << endl;
}

int Album::Add(AlbumType a)  //albumList에 콘텐츠 추가
{

	contentsList.Add(a);
	countOfAlbum++;
	return 1;
}
/*
* pre:albumList가 정의돼 있어야함
* post: 성공시 1 반환
*/
int Album::Delete(AlbumType item)  //albumList에 콘텐츠 삭제
{
	contentsList.Delete(item);
	if (countOfAlbum > 0)
		countOfAlbum--;
	return 1;
}
/*
* pre:albumList가 정의돼 있어야함
* post: 성공시 1 반환
*/
int Album::Retrieve(AlbumType item)  //albumList 콘텐츠 검색
{
	return contentsList.Retrieve(item);
}
/*
* pre:albumList가 정의돼 있어야함
* post: 성공시 1 , 실패시 0반환
*/
