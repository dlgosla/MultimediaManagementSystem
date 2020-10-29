#include "FC.h"

int FC::CompareByName(const FC& data)

{
	/*
	precondition: data�� name�� name�� ��ġ�ϴ� ���� �־�� �Ѵ�
	postcondition: name�� �������� �� �����͸� ���ϰ� ��Ȳ�� ���� less(0), grater(1), equal(2)�� ��ȯ�Ѵ�
	*/
	if (data.fileName > fileName)
		return 0;
	else if (data.fileName < fileName)
		return 1;
	else
		return 2;
}

int FC::getCountOfView() {
	return countOfView;
}

void FC::DisplayRecordOnScreen()
{
	cout << "������ �̸�: " << fileName << " �� �������� �� Ƚ��: " << countOfView << endl;
}
void FC::setRecord(string fileName, int countOfView )
{
	this->fileName = fileName;
//	this->memo = memo;
	this->countOfView = countOfView;

}
string FC::getFileName()
{
	return fileName;
}

void FC::view() { 
	countOfView++;
}
 