#include "EventType.h"

string EventType::GetName()
{
	/*
	precondition: name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �����Ѵ�
	*/
	return name;
}

string EventType::GetEvent()
{

	/*
	precondition:  event�� ���ǵ� �־�� �Ѵ�
	postcondition:  event�� �����Ѵ�
	*/
	return event;
}

void EventType::SetName(string inputName)
{
	/*
	precondition:  name�� ���ǵ� �־�� �Ѵ�
	postcondition: name�� �Է¹��� ������ �ٲ۴�
	*/
	name = inputName;
}

void EventType::SetEvent(string inputEvent)
{
	/*
	precondition: event�� ���ǵ� �־�� �Ѵ�
	postcondition: event�� �Է¹��� ������ �ٲ۴�
	*/
	event = inputEvent;
}

void EventType::SetRecord(string inputName, string inputEvent)
{
	/*
	precondition: name, kindOfContents, date, peoplem event�� ���� �� �־�� �Ѵ�
	postcondition: �� ������ �Է¹��� ������ �ٲ۴�
	*/
	name = inputName;
	event = inputEvent;
}

void EventType::DisplayNameOnScreen()
{
	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� ����Ѵ�
	*/
	cout << "������ ���ϸ�: " << name << endl;
}

void EventType::DisplayEventOnScreen()
{
	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition:  event�� ����Ѵ�
	*/
	cout << "�̺�Ʈ��: " << event << endl;
}

void EventType::DisplayRecordOnScreen(BinarySearchTree<ItemType>& master)
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ�
	*/
	//master.ResetList();
	ItemType item;
	item.SetName(name);
	bool found = false;
	master.RetrieveItem(item,found);
	item.DisplayRecordOnScreen();
}

void EventType::DisplayRecordOnScreen()
{
	/*
	precondition: name, kindOfContents, date, peoplem event, classification, memo�� ���ǵ� �־���Ѵ�
	postcondition: �� ��Ҹ� ����Ѵ�
	*/

	cout << "�̺�Ʈ ��: " << event << "������ �̸�: " << name << endl;
}

void EventType::SetNameFromKB()
{
	/*
	precondition: name�� ���ǵ� �־���Ѵ�
	postcondition: name�� �Է¹޴´�
	*/
	cout << "������ ���ϸ��� �Է����ּ���: ";
	cin >> name;
}

void EventType::SetEventFromKB()
{	/*
	precondition: event�� ���ǵ� �־���Ѵ�
	postcondition: event�� �Է¹޴´�
	*/
	cout << "�̺�Ʈ���� �Է����ּ���: ";
	cin >> event;
}


void EventType::SetRecordFromKB()
{	/*
	precondition: ������ �Լ����� ���ǵ� �־���Ѵ�
	postcondition: �Լ����� ȣ���Ѵ�
	*/
	SetNameFromKB();
	SetEventFromKB();
}
int EventType::ReadDataFromFile(ifstream& fin)
{
	/*
	precondition: fin�� ���ǵ� �־���Ѵ�
	postcondition: ���Ͽ��� �о���� �����ϸ� 1�� �����Ѵ�
	*/
	fin >> name >> event;

	return 1;
}
int EventType::WriteDataToFile(ofstream& fout)
{
	/*
	precondition: fout�� ���ǵ� �־�� �Ѵ�
	postcondition: �� �������� ���Ͽ� �����ϰ� �����ϸ� 1�� �����Ѵ�
	*/
	fout << name << " " << " " << event << endl;

	return 1;
}

RelationType EventType::CompareByName(const EventType& data)
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