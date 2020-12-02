#include "People.h"

UnsortedList<PeopleType>People::getList() {
	return contentsList;
}

RelationType People::CompareByName(const People& data)
{
	/*
	precondition: data의 name과 name이 일치하는 것이 있어야 한다
	postcondition: name을 기준으로 두 데이터를 비교하고 상황에 따라 less, grater, equal을 반환한다
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
* pre:length가 정의 돼 있어야함
* post: length 반환
*/

int People::getLength()
{
	return length;
}

/*
* pre: item의 key와 일치하는 데이터가 있어야 함
* post: item과 key가 일치하는 데이터 정보를 item으로 바꿈
*/

void People::replace(PeopleType item)
{
	contentsList.Replace(item);
}

/*
* 연산자 오버로딩
* post: 값을 비교하고 값 크기에 따라 true나 false를 리턴
*/

bool People::operator>(People item)
{
	return (this->getPeopleName() > item.getPeopleName());
}
/*
* post: 두 값의 key값이 같으면 true 아니면 false를 리턴
*/

bool People::operator==(People item)
{
	return (this->getPeopleName() == item.getPeopleName());
}

/*
	pre: PeopleName이 정의 돼 있어야 한다
	post: PeopleName을 리턴
*/

string People::getPeopleName()
{
	return PeopleName;
}

/*
* post: 각 파라미터의 값을 멤버 변수에 저장함
*/

void People::setRecord(string name, int len)
{
	PeopleName = name;
	length = len;
}
/*
* pre: 각 멤버변수가 정의돼 있어야함
* post: 정보가 저장됨
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
	cout << "사람: " << PeopleName << " 컨텐츠 수: " << length << endl;
}
/*
* 모든 정보를 보여줌
*/

int People::Add(PeopleType e)  //people List에 콘텐츠 추가
{
	contentsList.Add(e);
	length++;
	return 1;
}
/*
* pre:peopleList가 정의돼 있어야함, 동일한 key가 있으면 안됨
* post: 성공시 1 반환
*/
int People::Delete(PeopleType e)  //people List에 콘텐츠 삭제
{
	contentsList.Delete(e);
	if (length > 0)
		length--;
	return 1;
}
/*
* pre:peopleList가 정의돼 있어야함 삭제할 아이템의 key와 일치하는 key가 있어야함
* post: 성공시 1 반환
*/
int People::Retrieve(PeopleType e)  //people List 콘텐츠 검색
{
	return contentsList.Retrieve(e);
}
/*
* pre:peopleList가 정의돼 있어야함
* post: 성공시 1 , 실패시 0반환
*/