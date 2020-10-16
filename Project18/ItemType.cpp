#include "ItemType.h"


string ItemType::GetName()
{
	/*
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	return name;
}
int ItemType::GetkindOfContents()
{
	/*
	precondition: kindOfContents�� ���ǵ� �־�� �Ѵ�
	postcondition: kindOfContents�� �����Ѵ�
	*/
	return kindOfContents;
}
string ItemType::GetDate()
{

	/*
	precondition: date�� ���ǵ� �־�� �Ѵ�
	postcondition: date�� �����Ѵ�
	*/
	return date;
}
string ItemType::GetPeople()
{

	/*
	precondition: people�� ���ǵ� �־�� �Ѵ�
	postcondition: people�� �����Ѵ�
	*/
	return people;
}
string ItemType::GetEvent()
{

	/*
	precondition:  event�� ���ǵ� �־�� �Ѵ�
	postcondition:  event�� �����Ѵ�
	*/
	return event;
}

void ItemType::SetName(string inputName)
{
	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	name = inputName;
}
void ItemType::SetkindOfContents(int inputKindOfContents)
{
	/*
	precondition: kindOfContents�� ���ǵ� �־�� �Ѵ�
	postcondition: kindOfContents�� �Է¹��� ������ �ٲ۴�
	*/
	kindOfContents = inputKindOfContents;
}
void ItemType::SetDate(string inputDate)
{
	/*
	precondition: date�� ���ǵ� �־�� �Ѵ�
	postcondition: date�� �Է¹��� ������ �ٲ۴�
	*/
	date = inputDate;
}
void ItemType::SetPeople(string inputPeople)
{
	/*
	precondition:  people�� ���ǵ� �־�� �Ѵ�
	postcondition: people�� �Է¹��� ������ �ٲ۴�
	*/
	people = inputPeople;
}
void ItemType::SetEvent(string inputEvent)
{
	/*
	precondition: event�� ���ǵ� �־�� �Ѵ�
	postcondition: event�� �Է¹��� ������ �ٲ۴�
	*/
	event = inputEvent;
}

int ItemType::GetClassification()
{
	/*
	precondition:  classification�� ���ǵ� �־�� �Ѵ�
	postcondition:  classification�� �����Ѵ�
	*/
	return classification;
}
string ItemType::GetMemo()
{
	/*
	precondition:  memo�� ���ǵ� �־�� �Ѵ�
	postcondition:  memo�� �����Ѵ�
	*/
	return memo;
}
void ItemType::SetClassification(int inputClassification)
{
	/*
	precondition: classification�� ���ǵ� �־�� �Ѵ�
	postcondition: classification�� �Է¹��� ������ �ٲ۴�
	*/
	classification = inputClassification;
}
void ItemType::setMemo(string inputMemo)
{
	/*
	precondition: memo�� ���ǵ� �־�� �Ѵ�
	postcondition: memo�� �Է¹��� ������ �ٲ۴�
	*/
	memo = inputMemo;
}

void ItemType::SetRecord(string inputName, int inputKindOfContents, string inputDate, string inputPeople, string inputEvent, int  inputClassification, string inputMeno)
{
	/*
	precondition: name, kindOfContents, date, peoplem event�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	name = inputName;
	kindOfContents = inputKindOfContents;
	date = inputDate;
	people = inputPeople;
	event = inputEvent;
	classification = inputClassification;
	memo = inputMeno;
}

void ItemType::DisplayNameOnScreen()
{
	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� ����Ѵ�
	*/
	cout << "������ ���ϸ�: " << name << endl;
}
void ItemType::DisplayKindOnScreen()
{
	/*
	precondition: kindOfContents�� ���ǵ� �־���Ѵ�
	postcondition: kindOfContents�� ����Ѵ�
	*/
	cout << "������ ����: " << kindOfContents << endl;
}
void ItemType::DisplayDateOnScreen()
{
	/*
	precondition: date�� ���ǵ� �־���Ѵ�
	postcondition: date�� ����Ѵ�
	*/
	cout << "������¥�� �ð�: " << date << endl;
}

void ItemType::DisplayPeopleOnScreen()
{
	/*
	precondition: people�� ���ǵ� �־���Ѵ�
	postcondition: people�� ����Ѵ�
	*/
	cout << "�������� ���Ե� ���: " << people << endl;
}
void ItemType::DisplayEventOnScreen()
{
	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition:  event�� ����Ѵ�
	*/
	cout << "�̺�Ʈ��: " << event << endl;
}
void ItemType::DisplayClassificationOnScreen()
{
	/*
	precondition: classification�� ���ǵ� �־���Ѵ�
	postcondition:  classification�� ����Ѵ�
	*/
}
void ItemType::DisplayMemoOnScreen()
{
	/*
	precondition: memo�� ���ǵ� �־���Ѵ�
	postcondition:  memo�� ����Ѵ�
	*/
}

void ItemType::DisplayRecordOnScreen()
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ�
	*/
	cout << "������ ���ϸ�: " << name << " ������ ����: " << kindOfContents
		<< " ������¥�� �ð�: " << date << " �������� ���Ե� ���: " << people
		<< " �̺�Ʈ��: " << event << " ������ ����: "<< classification 
		<<" ������ ����: "<< memo <<endl;
}
void ItemType::SetNameFromKB()
{
	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� �Է¹޴´�
	*/
	cout << "������ ���ϸ��� �Է����ּ���: ";
	cin >> name;
}

void ItemType::SetKindFromKB()
{
	/*
	precondition: kindOfContents�� ���ǵ� �־���Ѵ�
	postcondition: kindOfContents�� �Է¹޴´�
	*/
	cout << "������ ������ �Է����ּ���: ";
	cin >> kindOfContents;
}
void ItemType::SetDateFromKB()
{
	/*
	precondition: date�� ���ǵ� �־���Ѵ�
	postcondition: date�� �Է¹޴´�
	*/
	cout << "������¥�� �ð��� �Է����ּ���: ";
	cin >> date;
}
void ItemType::SetPeopleFromKB()
{
	/*
	precondition: people�� ���ǵ� �־���Ѵ�
	postcondition: people�� �Է¹޴´�
	*/
	cout << "�������� ���Ե� ����� �Է����ּ���: ";
	cin >> people;
}
void ItemType::SetEventFromKB()
{	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition: event�� �Է¹޴´�
	*/
	cout << "�̺�Ʈ���� �Է����ּ���: ";
	cin >> event;
}


void ItemType::SetClassificationFromKB()
{
	/*
	precondition: classification�� ���ǵ� �־���Ѵ�
	postcondition: classification�� �Է¹޴´�
	*/
	cout << "������ ������ �Է����ּ���: ";
	cin >> classification;
}
void ItemType::SetMemoFromKB()
{
	/*
	precondition: memo�� ���ǵ� �־���Ѵ�
	postcondition: memo�� �Է¹޴´�
	*/
	cout << "������ ������ �Է����ּ���: ";
	cin >> memo;
}

void ItemType::SetRecordFromKB()
{	/*
	precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
	postcondition: �Լ����� ȣ���Ѵ�
	*/
	SetNameFromKB();
	SetKindFromKB();
	SetDateFromKB();
	SetPeopleFromKB();
	SetEventFromKB();
	SetClassificationFromKB();
	SetMemoFromKB();
}
int ItemType::ReadDataFromFile(ifstream& fin)
{
	/*
	precondition: fin�� ���ǵ� �־���Ѵ�
	postcondition: ���Ͽ��� �о���� �����ϸ� 1�� �����Ѵ�
	*/
	fin >> name >> kindOfContents >> date >> people >> event >> classification >> memo;

	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout)
{
	/*
	precondition: fout�� ���ǵ� �־�� �Ѵ�
	postcondition: �� �������� ���Ͽ� �����ϰ� �����ϸ� 1�� �����Ѵ�
	*/
	fout << name << " " << kindOfContents << " " << date << " " << people << " " << event << " " << classification << " " << memo << endl;

	return 1;
}
RelationType ItemType::CompareByName(const ItemType& data)
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