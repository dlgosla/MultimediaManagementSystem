#include "People.h"

UnsortedList<PeopleType>People::getList() {
	return contentsList;
}

RelationType People::CompareByName(const People& data)
{
	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less, grater, equal�� ��ȯ�Ѵ�
	*/
	if (data.PeopleName > PeopleName)
		return LESS;

	else if (data.PeopleName < PeopleName)
		return GREATER;
	else
		return EQUAL;

}

People::People()
{
	PeopleName = "";
	length = 0;
	contentsList.ResetList();
}


People::~People() {}

/*
* pre:length�� ���� �� �־����
* post: length ��ȯ
*/

int People::getLength()
{
	return length;
}

/*
* pre: item�� key�� ��ġ�ϴ� �����Ͱ� �־�� ��
* post: item�� key�� ��ġ�ϴ� ������ ������ item���� �ٲ�
*/

void People::replace(PeopleType item)
{
	contentsList.Replace(item);
}

/*
* ������ �����ε�
* post: ���� ���ϰ� �� ũ�⿡ ���� true�� false�� ����
*/

bool People::operator>(People item)
{
	return (this->getPeopleName() > item.getPeopleName());
}
/*
* post: �� ���� key���� ������ true �ƴϸ� false�� ����
*/

bool People::operator==(People item)
{
	return (this->getPeopleName() == item.getPeopleName());
}

/*
	pre: PeopleName�� ���� �� �־�� �Ѵ�
	post: PeopleName�� ����
*/

string People::getPeopleName()
{
	return PeopleName;
}

/*
* post: �� �Ķ������ ���� ��� ������ ������
*/

void People::setRecord(string name, int len)
{
	PeopleName = name;
	length = len;
}
/*
* pre: �� ��������� ���ǵ� �־����
* post: ������ �����
*/

void People::printRecord(BinarySearchTree<ItemType>& master)
{
	contentsList.DisplayRecord(master);
}


void People::printRecord()
{
	contentsList.DisplayRecord();
}


void People::DisplayRecordOnScreen() {
	cout << "���: " << PeopleName << " ������ ��: " << length << endl;
}
/*
* ��� ������ ������
*/

int People::Add(PeopleType e)  //people List�� ������ �߰�
{
	contentsList.Add(e);
	length++;
	return 1;
}
/*
* pre:peopleList�� ���ǵ� �־����, ������ key�� ������ �ȵ�
* post: ������ 1 ��ȯ
*/
int People::Delete(PeopleType e)  //people List�� ������ ����
{
	contentsList.Delete(e);
	if (length > 0)
		length--;
	return 1;
}
/*
* pre:peopleList�� ���ǵ� �־���� ������ �������� key�� ��ġ�ϴ� key�� �־����
* post: ������ 1 ��ȯ
*/
int People::Retrieve(PeopleType e)  //people List ������ �˻�
{
	return contentsList.Retrieve(e);
}
/*
* pre:peopleList�� ���ǵ� �־����
* post: ������ 1 , ���н� 0��ȯ
*/