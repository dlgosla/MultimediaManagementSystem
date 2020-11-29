#include "AlbumType.h"

AlbumType::AlbumType()
{
	name = ""; //������ ���ϸ�
	album = ""; //�ٹ���
}
AlbumType::~AlbumType()
{

}

void AlbumType::DisplayRecordOnScreen(SortedList<ItemType>& master)
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ�
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
	postcondition: ����Ѵ�
	*/

	cout << " ������ �̸�: " << name << endl;
}

/*
precondition: name�� ���ǵ� �־�� �Ѵ�
postcondition: name�� �����Ѵ�
*/
string AlbumType::GetName() {
	return name;
}

/*
precondition:  album�� ���ǵ� �־�� �Ѵ�
postcondition:  album�� �����Ѵ�
*/
string AlbumType::GetAlbum() {
	return album;
}

/*
precondition:  name�� ���ǵ� �־�� �Ѵ�
postcondition: name�� �Է¹��� ������ �ٲ۴�
*/
void AlbumType::SetName(string inputName)
{
	name = inputName;
}

/*
precondition: album�� ���ǵ� �־�� �Ѵ�
postcondition: album�� �Է¹��� ������ �ٲ۴�
*/
void AlbumType::SetAlbum(string inputAlbum)
{
	album = inputAlbum;
}
/*
precondition: name, kindOfContents, date, peoplem album�� ���� �� �־�� �Ѵ�
postcondition: �� ������ �Է¹��� ������ �ٲ۴�
*/
void AlbumType::SetRecord(string name, string album)
{
	SetName(name);
	SetAlbum(album);
}

/*
precondition: name�� ���ǵ� �־���Ѵ�
postcondition: name�� ����Ѵ�
*/
void AlbumType::DisplayNameOnScreen()
{
	cout << "������ ���ϸ�: " << name << endl;
}

/*
precondition: album�� ���ǵ� �־���Ѵ�
postcondition:  album�� ����Ѵ�
*/
void AlbumType::DisplayAlbumOnScreen()
{
	cout << "�ٹ���: " << album << endl;
}

/*
precondition: name, kindOfContents, date, peoplem album, classification, memo�� ���ǵ� �־���Ѵ�
postcondition: �� ��Ҹ� ����Ѵ�
*/
void AlbumType::DisplayRecord()
{
	cout << "������ ���ϸ�: " << name << "�ٹ���: " << album << endl;
}

/*
precondition: name, kindOfContents, date, peoplem album, classification, memo�� ���ǵ� �־���Ѵ�
postcondition: �� ��Ҹ� ����Ѵ�
*/
//void DisplayRecordOnScreen(SortedList<ItemType>& master);

/*
precondition: name�� ���ǵ� �־���Ѵ�
postcondition: name�� �Է¹޴´�
*/
void AlbumType::SetNameFromKB()
{
	cout << "������ ���ϸ��� �Է����ּ���: ";
	cin >> name;

}

/*
precondition: album�� ���ǵ� �־���Ѵ�
postcondition: album�� �Է¹޴´�
*/
void AlbumType::SetAlbumFromKB()
{
	cout << "�ٹ����� �Է����ּ���: ";
	cin >> album;
}

/*
precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
postcondition: �Լ����� ȣ���Ѵ�
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
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	if (data.name > name)
		return LESS;

	else if (data.name < name)
		return GREATER;
	else
		return EQUAL;

}