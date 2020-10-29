#include "FC.h"

int FC::CompareByName(const FC& data)

{
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less(0), grater(1), equal(2)을 반환한다
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
	cout << "콘텐츠 이름: " << fileName << " 이 콘텐츠를 본 횟수: " << countOfView << endl;
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
 