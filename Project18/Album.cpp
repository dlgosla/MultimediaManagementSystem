#include "Album.h"

RelationType Album::CompareByName(const Album& data)
{
	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
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
* pre:countOfAlbum�� ���� �� �־����
* post: countOfAlbum ��ȯ
*/
int Album::getCountOfAlbum()
{
	return countOfAlbum;
}

/*
* pre: item�� key�� ��ġ�ϴ� �����Ͱ� �־�� ��
* post: item�� key�� ��ġ�ϴ� ������ ������ item���� �ٲ�
*/
void Album::replace(AlbumType item)
{
	contentsList.Replace(item);
}

/*
* ������ �����ε�
* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
*/
bool Album::operator>(Album item)
{
	return this->albumName > item.getAlbumName();
}
/*
* post: �� ���� key���� ������ true �ƴϸ� false�� ����
*/
bool Album::operator==(Album item)
{
	return this->albumName == item.getAlbumName();
}

/*
	pre: albumName�� ���� �� �־�� �Ѵ�
	post: albumName�� ����
*/
string Album::getAlbumName()
{
	return albumName;
}

/*
* post: �� �Ķ������ ���� ��� ������ ������
*/
void Album::setRecord(string e_name, string desc, int count)
{
	albumName = e_name;
	description = desc;
	countOfAlbum = count;
}
/*
* pre: �� ��������� ���ǵ� �־����
* post: �ڼ��� ������ ���
*/
void Album::printRecord(SortedList<ItemType>& master) {
	contentsList.DisplayRecord(master);
}

void Album::printRecord() {
	contentsList.DisplayRecord();
}

/*
* ������ ������ ������
*/
void Album::DisplayRecordOnScreen() {
	cout << "�ٹ���: " << albumName << " �ٹ�����: " << description << " ������ ��: " << countOfAlbum << endl;
}

int Album::Add(AlbumType a)  //albumList�� ������ �߰�
{

	contentsList.Add(a);
	countOfAlbum++;
	return 1;
}
/*
* pre:albumList�� ���ǵ� �־����
* post: ������ 1 ��ȯ
*/
int Album::Delete(AlbumType item)  //albumList�� ������ ����
{
	contentsList.Delete(item);
	if (countOfAlbum > 0)
		countOfAlbum--;
	return 1;
}
/*
* pre:albumList�� ���ǵ� �־����
* post: ������ 1 ��ȯ
*/
int Album::Retrieve(AlbumType item)  //albumList ������ �˻�
{
	return contentsList.Retrieve(item);
}
/*
* pre:albumList�� ���ǵ� �־����
* post: ������ 1 , ���н� 0��ȯ
*/
