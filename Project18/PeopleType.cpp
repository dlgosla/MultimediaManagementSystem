#include "PeopleType.h"

PeopleType::PeopleType()
{
	contentsName = ""; //������ ���ϸ�
	people = ""; //����̸�
}
PeopleType::~PeopleType() {}


/*
precondition: name�� ���ǵ� �־�� �Ѵ�
postcondition: name�� �����Ѵ�
*/
string PeopleType::GetContentsName()
{
	return contentsName;
}

/*
precondition:  people�� ���ǵ� �־�� �Ѵ�
postcondition:  people�� �����Ѵ�
*/
string PeopleType::GetPeople()
{
	return people;
}

/*
precondition:  name�� ���ǵ� �־�� �Ѵ�
postcondition: name�� �Է¹��� ������ �ٲ۴�
*/
void PeopleType::SetContentsName(string inputName)
{
	contentsName = inputName;
}

/*
precondition: people�� ���ǵ� �־�� �Ѵ�
postcondition: people�� �Է¹��� ������ �ٲ۴�
*/
void PeopleType::SetPeople(string inputPeople)
{
	people = inputPeople;
}

/*
precondition: name, kindOfContents, date, peoplem people�� ���� �� �־�� �Ѵ�
postcondition: �� ������ �Է¹��� ������ �ٲ۴�
*/
void PeopleType::SetRecord(string Name, string people)
{
	contentsName = Name;
	this->people = people;
}


/*
precondition: name, kindOfContents, date, peoplem people, classification, memo�� ���ǵ� �־���Ѵ�
postcondition: �� ����� �ڼ��� ������ ����Ѵ�
*/
void PeopleType::DisplayRecordOnScreen(SortedList<ItemType>& master)
{
	master.ResetList();
	ItemType item;
	item.SetName(contentsName);
	master.Retrieve_SeqS(item);
	item.DisplayRecordOnScreen();
}

/*
precondition: name, kindOfContents, date, peoplem people, classification, memo�� ���ǵ� �־���Ѵ�
postcondition: �� ��Ҹ� ����Ѵ�
*/
void PeopleType::DisplayRecordOnScreen()
{
	cout << "�����: " << people << "������ �̸�: " << contentsName << endl;
}

/*
precondition: name�� ���ǵ� �־���Ѵ�
postcondition: name�� �Է¹޴´�
*/
void PeopleType::SetContentsNameFromKB()
{
	cout << "������ ���ϸ��� �Է����ּ���: ";
	cin >> contentsName;
}

/*
precondition: people�� ���ǵ� �־���Ѵ�
postcondition: people�� �Է¹޴´�
*/
void PeopleType::SetPeopleFromKB()
{
	cout << "����̸� �Է����ּ���: ";
	cin >> people;
}

/*
precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
postcondition: �Լ����� ȣ���Ѵ�
*/
void PeopleType::SetRecordFromKB()
{
	SetContentsNameFromKB();
	SetPeopleFromKB();
}

/*
precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
*/
RelationType PeopleType::CompareByName(const PeopleType& data)// primary key (ID)�������������������������ϴ��Լ�
{
	if (data.contentsName > contentsName)
		return LESS;

	else if (data.contentsName < contentsName)
		return GREATER;
	else
		return EQUAL;
}