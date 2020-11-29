#include "Application.h"
#include "ItemType.h"
#include "SortedList.h"

void Application::Display_Detail_Pic_FC() {
	fc_picList.DisplayRecord(m_List);
}


void Application::Display_Detail_Video_FC() {
	fc_videoList.DisplayRecord(m_List);
}


void Application::searchPeopleInEvent() {
	Event e = FindNDisplayEvent();
	UnsortedList<EventType> eList = e.getList();
	bool found = false;

	cout << "ã����� ���: " << endl;
	string pName;
	cin >> pName;
	People p;
	p.setRecord(pName);
	peopleList.Retrieve_BinaryS(p);
	UnsortedList<PeopleType> pList = p.getList();

	PeopleType pItem;
	EventType eItem;
	Album album;
	AlbumType aItem;

	eList.ResetList();
	while (eList.GetNextItem(eItem) != -1) {
		pItem.SetContentsName(eItem.GetName());
		if (pList.Retrieve(pItem) != 0) {
			pItem.DisplayRecordOnScreen(m_List);
			aItem.SetRecord(pItem.GetContentsName());
			album.Add(aItem);
			
			found = true;
		}
	}

	if (found == true) {
		cout << "�ٹ��� �߰��Ͻðڽ��ϱ�?(y/n)" << endl;
		char user;
		cin >> user;
		if (user == 'y') { //�߰��ϰڴٰ� �ϸ�
			string aName;
			cout << "�ٹ��̸�: "; //�ٹ��̸��� �޾ƿ���
			cin >> aName;
			album.setRecord(aName);
			albumList.Add(album); //�ٹ�����Ʈ�� �߰�
			
		}
	}

}


void Application::searchEventInPeople()
{
	People p = printPeople();
	UnsortedList<PeopleType> pList = p.getList();
	bool found = false;

	cout << "ã����� �̺�Ʈ: " << endl;
	string eName;
	cin >> eName;
	Event e;
	e.setRecord(eName);
	eventList.Get(e);
	UnsortedList<EventType> eList = e.getList();

	PeopleType pItem;
	EventType eItem;
	Album album;
	AlbumType aItem;

	pList.ResetList();
	while (pList.GetNextItem(pItem) != -1) {
		eItem.SetName(pItem.GetContentsName());
		if (eList.Retrieve(eItem) != 0) {
			eItem.DisplayRecordOnScreen(m_List);
			aItem.SetRecord(eItem.GetName());
			album.Add(aItem);
			found = true;
		}
	}

	if (found == true) {
		cout << "�ٹ��� �߰��Ͻðڽ��ϱ�?(y/n)" << endl;
		char user;
		cin >> user;
		if (user == 'y') { //�߰��ϰڴٰ� �ϸ�
			string aName;
			cout << "�ٹ��̸�: "; //�ٹ��̸��� �޾ƿ���
			cin >> aName;
			album.setRecord(aName);
			albumList.Add(album); //�ٹ�����Ʈ�� �߰�
		}
	}
}


void Application::runPeople() {
	while (1) {
		cout << "=======================" << endl;
		cout << "1.	��ü ��� �׷� ����" << endl;
		cout << "2.	Ư�� ����� ���Ե� ������ ����" << endl;
		cout << "3. Ư�� ����� ���Ե� ������ ������ �˻� " << endl;
		cout << "�̿��� ����:exit" << endl;
		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;

		switch (command)
		{
		case 1:
			printAllGroup();
			break;
		case 2:
			printPeople();
			break;
		case 3:
			searchEventInPeople();
			break;
		default:
			return;
			break;
		}
	}
}


void Application::addPeople(string pName, string contentsName)
{
	PeopleType pItem;

	vector<string> pArray;

	// CŸ�� ���ڿ��� ��ȯ
	char* buffer = new char[1000];
	strcpy(buffer, pName.c_str());

	// ���ڿ� �ڸ���
	char* tok = strtok(buffer, ",");
	while (tok != NULL) {
		pArray.push_back(string(tok));
		tok = strtok(NULL, ",");
	}

	for (int i = 0; i < pArray.size(); i++) { //�������� ���Ե� ����鿡 ���� ���ʴ��;
		People people;
		people.setRecord(pArray[i]); //�����ü
		pItem.SetPeople(pName); //��� ��ü ���� ������
		pItem.SetContentsName(contentsName);
		people.Add(pItem); //�� ��� ��ü�� ������ �߰�

		if (peopleList.Retrieve_BinaryS(people) == 1) //�������Ʈ�� �� ��� ��ü�� ������
		{
			people.Add(pItem); //�� ��� ��ü�� ������ �߰�
			peopleList.Replace(people); //�������Ʈ ������Ʈ
		}
		else { //������
			peopleList.Add(people); //�� ��� ��ü�� �߰�
		}
	}

	// Ȯ��
//	for (int i = 0; i < pArray.size(); i++) cout << strArr[i] << "\n";

}


void Application::printAllGroup()
{
	peopleList.ResetList();
	People p;
	for (int i = 0; i < peopleList.GetLength(); i++)
	{
		peopleList.GetNextItem(p);
		cout << "=======��� " << p.getPeopleName() << "��(��) ���Ե� ������========" << endl;
		p.printRecord(m_List);
		cout << "=========================================" << endl;
	}
}


People Application::printPeople()
{
	string pName;
	cout << "������� �Է��ϼ���: ";
	cin >> pName;

	People temp;
	temp.setRecord(pName);
	peopleList.Retrieve_BinaryS(temp);
	cout << "========��� " << pName << "�� ���Ե� ������========" << endl;
	temp.printRecord(m_List);
	cout << "============================" << endl;
	return temp;
}


void Application::runAlbum() {
	/*
	* pre:none
	* post: �ٹ��� ���õ� �޴�
	*/
	while (1) {
		cout << "======�ٹ� �޴�=====" << endl;
		cout << "1. �ٹ� �̸� �߰�" << endl;
		cout << "2. �ٹ� �̸� ����" << endl;
		cout << "3. �ٹ��� ���� �߰�" << endl;
		cout << "4. �ٹ��� ���� ����" << endl;
		cout << "5. �ٹ� ���� ����" << endl;
		cout << "�ٸ�����: �ڷΰ���" << endl;
		cout << "==================" << endl;

		int input;
		cout << ">> ";
		cin >> input;

		switch (input)
		{
		case 1:
			addAlbum();
			break;
		case 2:
			deleteAlbum();
			break;
		case 3:
			addContentsInAlbum();
			break;
		case 4:
			deleteContentsInAlbum();
			break;
		case 5:
			printAllAlbum();
			break;
		default:
			return;
		}

	}

}


void Application::deleteContentsInAlbum()
{
	/*
	* pre: �ٹ����� �ٹ� ����Ʈ�� �־�� �Ѵ�, �� �ٹ��ȿ� �ش� �������� �־���Ѵ�
	* post: �ٹ��̸��� ������ �̸��� Ű����� �Է¹޾Ƽ� �� �ٹ��ȿ��� �ش� �������� �����Ѵ�
	*/
	Album album;
	albumList.DisplayRecord();
	cout << "�ٹ� ����: ";
	string inputAlbum;
	cin >> inputAlbum; //������ ������ �ٹ��� 
	album.setRecord(inputAlbum);
	albumList.Retrieve_SeqS(album); // �ٹ�����Ʈ���� �ٹ��� ã�Ƽ� ����
	AlbumType item;

	while (true) {
		cout << "======= " << inputAlbum << " ���� �������� �����մϴ�. ====" << endl;
		//album.DisplayRecordOnScreen();
		album.printRecord(); //������
		cout << "========================" << endl;
		item.SetNameFromKB(); //�ٹ������� �����ϰ� ���� �������̸�

		album.Delete(item); //������ ����

		int user;
		cout << "�׸� �����Ϸ��� 0�� �Է����ּ���" << endl;
		cin >> user;
		if (!user) {
			break;
		}
	}
	albumList.Replace(album); //�ٹ� ������Ʈ
}



void Application::addContentsInAlbum() {
	/*
	* pre: �ٹ����� �ٹ�����Ʈ�� �־�� �Ѵ�, �� �ٹ� �׷쿡 �߰��� �������� �ߺ��� �������� ������Ѵ�
	* post: Ư�� �ٹ����� �Է¹޾� �� �ٹ��׷쿡 �������� �߰��Ѵ�
	*/
	if (albumList.IsEmpty()) { //���������
		cout << "�ٹ��� ���� �������ּ���" << endl;
	}
	cout << "�������� �߰��ϰ� ���� �ٹ� ����: " << endl;
	albumList.DisplayRecord();
	cout << "=================" << endl;

	string inputName; //�ٹ��̸� �Է�
	cout << ">> ";
	cin >> inputName;

	Album aItem; //�˻��� ���� �ٹ� ��ü ����
	aItem.setRecord(inputName);
	albumList.Retrieve_BinaryS(aItem); //�Է¹��� �ٹ��̸��� ���� �ٹ��� ã�� aItem�� �ҷ���

	cout << "�ٹ��� �߰��ϰ� ���� ������ ����" << endl;
	m_List.DisplayRecord(); //�ִ� ������ ���

	cout << "============================" << endl;

	AlbumType item;

	while (true) {
		item.SetNameFromKB(); //Ű����κ��� �Է¹���
		item.SetAlbum(inputName); //�ٹ����� ���

		ItemType temp;
		temp.SetName(item.GetName()); //�����͸���Ʈ �˻��� ���� temp��ü ����
		if (m_List.Retrieve_BinaryS(temp) == 0) { //�����͸���Ʈ�� �������� ������
			cout << "���� ������ �Դϴ�" << endl;
		}
		else { // ������
			aItem.Add(item); //�ٹ� �ȿ� �ش� ������ �߰�
		}
		cout << "�׸��Ϸ��� 0�� �Է��ϼ���" << endl;
		int user;
		cin >> user;
		if (user == 0) //0�� �����ϸ� ����
			break;
	}
	albumList.Replace(aItem); //�ٹ����� ������Ʈ
}


void Application::addAlbum() {
	string aName;
	Album a;

	cout << "�ٹ� ��: ";
	cin >> aName;

	string desc;
	cout << "�ٹ� ����: ";
	cin >> desc;

	a.setRecord(aName, desc);
	albumList.Add(a); //�ٹ�����Ʈ�� �ٹ� �߰�

}


int Application::deleteAlbum()
{
	/*
	* pre: �ٹ��� �ϳ��̻� �����ؾ��Ѵ�
	* post: �� �̸��� �ٹ������� ������ �ٹ��� �����Ѵ�
	*/
	string aName;
	Album a;

	cout << "�ٹ� ��: ";
	cin >> aName;

	a.setRecord(aName);
	albumList.Delete(a); //�ٹ�����Ʈ���� �ٹ�����

	return 1;
}


void Application::printAllAlbum() {
	albumList.ResetList();
	Album a;
	for (int i = 0; i < albumList.GetLength(); i++)
	{
		albumList.GetNextItem(a);
		cout << "=======�ٹ� " << a.getAlbumName() << "�� ������========" << endl;
		a.printRecord(m_List);
		cout << "=========================================" << endl;
	}
}



void Application::Application::printAllEvent()
{
	/*
	* pre: �̺�Ʈ�� �����ؾ���
	* post: �����ϴ� ��� �̺�Ʈ�� �ű� ���ϴ� ������ ���
	*/
	eventList.ResetList();
	Event e;
	for (int i = 0; i < eventList.GetLength(); i++)
	{

		eventList.GetNextItem(e);
		cout << "=======�̺�Ʈ " << e.getEventName() << "�� ������========" << endl;
		e.printRecord(m_List);
		cout << "=========================================" << endl;
	}

}


int Application::deleteEvent()
{
	/*
	* pre:�̺�Ʈ ���� �̺�Ʈ ����Ʈ�� �־�� ��
	* post: ����ڿ��� �̺�Ʈ���� �Է¹޾� �ϳ��� �̺�Ʈ �׷��� �����ϰ� ������ 1 ����
	*/
	string eName;
	Event e;

	cout << "�̺�Ʈ ��: ";
	cin >> eName;

	e.setRecord(eName);
	eventList.Delete(e);


	return 1;
}

int Application::addEvent()
{
	/*
	* pre:�̺�Ʈ ���� �̺�Ʈ ����Ʈ�� ����� ��
	* post: �� �̺�Ʈ�� ������ �̺�Ʈ Ÿ���� ��带 ����� ������ 1 ����
	*/
	string eName;
	Event e;

	cout << "�̺�Ʈ ��: ";
	cin >> eName;

	e.setRecord(eName);
	eventList.Add(e);

	return 1;

}
int Application::AddContents()
{
	/*
	�������� �Է¹޾Ƽ� �����͸���Ʈ, �̺�Ʈ����Ʈ, FC����Ʈ�� �����Ѵ�
	precondition: primary key�� �ߺ��Ǹ� �ȵȴ�
	postcondition: �߰��ϰ� �����ϸ� 1 �����ϸ� 0�� ��ȯ�Ѵ�
	*/
	if (m_List.IsFull())
	{
		cout << "�� á���ϴ�" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB(); //�������� �Է¹޾Ƽ�
	int result = m_List.Add(item);  //������ ����Ʈ�� �������� �߰�
	if (result == 0)
		return 0;

	//�̺�Ʈ ����Ʈ�� ������ �߰�
	EventType eItem;
	Event e;
	eItem.SetRecord(item.GetName(), item.GetEvent()); //�̺�Ʈ Ÿ�Կ� ������ ���� �߰�
	e.setRecord(item.GetEvent()); //�̺�Ʈ�� ������ ���� �߰�

	eventList.Add(e); //�̺�Ʈ ����Ʈ�� �̺�Ʈ �߰�

	eventList.Get(e);
	e.Add(eItem);
	eventList.Replace(e); //�̺�Ʈ ����Ʈ ���� �̺�Ʈ�� ������ �߰�

	//�������Ʈ�� �߰�
	addPeople(item.GetPeople(), item.GetName());

	//fc ����Ʈ�� �߰�
	string user;

	while (true)
	{
		cout << "���ã��� �߰��Ͻðڽ��ϱ�?(yes/no)" << endl;
		cin >> user;

		if (user == "yes")
		{
			FC temp;
			temp.setRecord(item.GetName());
			fc_list.Add(temp);
			if (item.GetkindOfContents() == 1)
				fc_picList.Add(temp);
			else if (item.GetkindOfContents() == 2)
				fc_videoList.Add(temp);
			break;
		}

		else if (user == "no")
		{
			cout << "�߰����� �ʽ��ϴ�" << endl;
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}
	DisplayAllContents();
	return 1;
}


Event Application::FindNDisplayEvent() //�̺�Ʈ �̸��� �Է¹޾Ƽ� �ű� �Ҽӵ� �������� �ڼ��� ������ ���
{
	string eName;
	cout << "�̺�Ʈ ���� �Է��ϼ���: ";
	cin >> eName;

	Event temp;
	temp.setRecord(eName);
	eventList.Get(temp);
	cout << "========�̺�Ʈ " << eName << "�� ������========" << endl;
	temp.printRecord(m_List);
	cout << "============================" << endl;
	return temp;
}

Application::Application()
{
	m_Command = 0;
}
Application::~Application() {}

int Application::Add_FC() //�������� �����Ͽ� FC_list�� �߰�
{
	/*
	* pre: m_List�� ���ǵ� �־�� �Ѵ�. �̹� FC����Ʈ�� ����� �ִ� �������� �Է��ϸ� �ȵȴ�.
	*	��ü ������ ����߿� �ش� �������� �־���Ѵ�.
	* post: ��ġ�ϴ� �����͸� ã�� �����ϸ� 1 �����ϸ� 0�� ����
	*/
	ItemType item;

	item.SetNameFromKB();	//name�� �Է¹޴´�
	if (m_List.Retrieve_BinaryS(item))	//����Ž���� �����ߴٸ�
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		FC temp;
		int count;
		cout << "�� �������� �� Ƚ��: ";
		cin >> count;
		temp.setRecord(item.GetName(), count);
		fc_list.Add(temp);

		if (item.GetkindOfContents() == 1)
			fc_picList.Add(temp);

		else if (item.GetkindOfContents() == 2)
			fc_videoList.Add(temp);

		//unsortedFC.Add(temp);
		cout << "<============I ����Ϸ� !==========>" << endl;
		return 1;
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;
}

void Application::Delete_FC_list() //�Էµ� FC�� FC_list���� ����
{
	string name;
	cout << "������ FC�� �̸�: ";
	cin >> name;
	FC temp;
	temp.setRecord(name);
	fc_list.Delete(temp);
	fc_picList.Delete(temp);
	fc_videoList.Delete(temp);

	//unsortedFC.Delete(temp);
}

void Application::Display_FC_list() //FC_list�� ����ִ� ������ ȭ�鿡 ���
{
	fc_list.DisplayRecord();
}


void Application::Display_Detail_FC()// Ư�� FC�� �ڼ��� ����(master list�� ����� ����)�� ȭ�鿡 ���
{
	string name;
	fc_list.DisplayRecord(m_List);
}


void Application::runFC()
{
	while (1) {
		cout << "=======================" << endl;
		cout << "1. FC�߰� " << endl;
		cout << "2. FC����: " << endl;
		cout << "3.FC ��� ����" << endl;
		cout << "4. FC �ڼ��� ���� ���  " << endl;
		cout << "5. ���� FC����" << endl;
		cout << "6. ���� FC����" << endl;
		cout << "�̿��� ����: exit" << endl;

		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 1:
			Add_FC();
			break;
		case 2:
			Delete_FC_list();
			break;
		case 3:
			Display_FC_list();
			break;
		case 4:
			Display_Detail_FC();
			break;
		case 5:
			Display_Detail_Pic_FC();
			break;
		case 6:
			Display_Detail_Video_FC();
			break;
		default:
			return;
			break;
		}
	}
}

void Application::run1()
{

	while (1) {
		cout << "=======================" << endl;
		cout << "1. �⺻ �޴�" << endl;
		cout << "2. FC �޴�" << endl;
		cout << "3. �̺�Ʈ �޴�" << endl;
		cout << "4. �ٹ� �޴�" << endl;
		cout << "5. ��� �޴�" << endl;
		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 1:
			Run();
			break;
		case 2:
			runFC();
			break;
		case 3:
			runEvent();
			break;
		case 4:
			runAlbum();
			break;
		case 5:
			runPeople();
			break;
		default:
			return;
		}
	}
}


void Application::runEvent() {
	while (1) {
		cout << "=======================" << endl;
		cout << "1. �̺�Ʈ �߰�" << endl;
		cout << "2. �̺�Ʈ ����" << endl;
		cout << "3.	��ü �̺�Ʈ ��� ����" << endl;
		cout << "4.	Ư�� �̺�Ʈ �� �������� ����" << endl;
		cout << "5. Ư�� �̺�Ʈ �ӿ��� ��� ã��" << endl;
		cout << "�̿��� ����:exit" << endl;
		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;

		switch (command)
		{
		case 1:
			addEvent();
			break;
		case 2:
			deleteEvent();
			break;
		case 3:
			printAllEvent();
			break;
		case 4:
			FindNDisplayEvent();
			break;
		case 5:
			searchPeopleInEvent();
			break;
		default:
			return;
			break;
		}
	}
}



int Application::SearchByName_BinaryS()
{
	/*
	* pre: m_List�� ���ǵ� �־�� �Ѵ�
	* post: ��ġ�ϴ� �����͸� ã�� �����ϸ� 1 �����ϸ� 0�� ����
	*/
	ItemType item;

	item.SetNameFromKB();	//name�� �Է¹޴´�
	if (m_List.Retrieve_BinaryS(item))	//����Ž���� �����ߴٸ�
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ

}

int Application::SearchByName_SequenS()
{
	/*
	* pre: m_List�� ���ǵ� �־�� �Ѵ�
	* post: ��ġ�ϴ� �����͸� ã�� �����ϸ� 1 �����ϸ� 0�� ����
	*/
	ItemType data;
	data.SetNameFromKB();

	if (m_List.Retrieve_SeqS(data))
	{
		data.DisplayRecordOnScreen();
		return 1;
	}
	cout << "�����ϴ�" << endl;
	return 0;
}

int Application::SearchAllItmeByPeople(ItemType& data)
{
	/*
	* pre: ���� ����
	* post: ã���� 1 ��ã���� 0 ��ȯ
	*/
	ItemType tmp;
	int result = 0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while (m_List.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetPeople().find(data.GetPeople()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

int Application::SearchByPeople()
{
	/*
	* pre: ���� ����
	* post: �Էµ� �̸��� ���Ե� �������� ��� ã�� ���� 1 ���� 0 ��ȯ
	*/
	ItemType item;
	item.SetPeopleFromKB(); //people�� �Է¹޴´�.

	if (SearchAllItmeByPeople(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

int Application::replaceItem()
{
	ItemType item;
	item.SetRecordFromKB();

	m_List.Replace(item);
	cout << "=======================";
	DisplayAllContents();
	cout << "=======================";
	return 0;
}


int Application::DeleteContents()
{
	/*
		precondition: data�� m_List�ȿ� �־�� �Ѵ�
		postcondition: m_List���� data�� ��ġ�ϴ� ���ڵ带 �����ϰ� �����ϸ� 1, �����ϸ� 0�� ��ȯ
	*/
	ItemType data;
	data.SetNameFromKB();
	if (m_List.Retrieve_SeqS(data) == 0)  //������ �����͸� ã�´�
	{
		return 0;
	}
	EventType eItem;
	eItem.SetName(data.GetName());

	// �̺�Ʈ����Ʈ���� ����
	Event e;
	e.setRecord(data.GetEvent()); //�̺�Ʈ ��ü
	eventList.Get(e); //�� �̺�Ʈ ��ü�� �����ͼ�
	e.Delete(eItem); // �� �̺�Ʈ ��ü���� ������ ����
	if (e.getCountOfEvent() == 0) { //�̺�Ʈ�� �������� ������
		eventList.Delete(e); //�̺�Ʈ ����
	}
	eventList.Replace(e); //�̺�Ʈ ����Ʈ ������Ʈ


	//fc����Ʈ���� ����
	FC temp;
	temp.setRecord(data.GetName()); //fc��ü
	fc_list.Delete(temp); //fc����Ʈ���� fc ������ ����
	fc_picList.Delete(temp);
	fc_videoList.Delete(temp);

	//��� ����Ʈ���� ����
	People p;
	PeopleType pItem;

	peopleList.ResetList();
	while (peopleList.GetNextItem(p) != -1) {//��� ����Ʈ�� ���鼭
		UnsortedList<PeopleType> tempList = p.getList(); //�� ����� ������ ���� ����Ʈ
		tempList.ResetList();
		while (tempList.GetNextItem(pItem) != -1) { //�� ����� ���Ե� ������ ���� ����Ʈ�� ���鼭
			if (pItem.GetContentsName() == data.GetName()) { //���� �����Ϳ� ��ġ�ϴ� �����Ͱ� ������
				p.Delete(pItem); //��� ��ü���� �������� ����
			}
		}
		peopleList.Replace(p); //������Ʈ
	}

	Album a;
	AlbumType aItem;

	albumList.ResetList();
	while (albumList.GetNextItem(a) != -1) { //�ٹ�����Ʈ�� ���鼭
		aItem.SetName(data.GetName());
		a.Delete(aItem); //��ġ�ϴ� �������� �ٹ����� ����
		albumList.Replace(a); //������Ʈ
	}

	int result = m_List.Delete(data); //�����͸���Ʈ���� ����
	m_List.DisplayRecord();
	return result;
}
int Application::ReplaceContents()
{
	/*
		precondition: m_List�� ���ǵ� �־�� �Ѵ�, m_List�� data�� primary key�� ��ġ�ϴ� ���� �־�� �Ѵ�
		postcondition: primary key�� ��ġ�ϴ� ���ڵ带 data�� ������ ��ü�ϰ� ������ 1 ���н� 0�� ��ȯ
	*/
	ItemType data;
	data.SetRecordFromKB();
	cout << "=======================" << endl;
	int result = m_List.Replace(data); //�����͸���Ʈ ��ü

	return result;


	//�̺�Ʈ ����Ʈ ��ü
	Event eTemp;
	eTemp.setRecord(data.GetName());
	eventList.Get(eTemp);
	EventType eItem;
	eItem.SetName(data.GetName());
	eTemp.replace(eItem);

	//FC����Ʈ ��ü
	FC fcTemp;
	fcTemp.setRecord(data.GetName());
	fc_list.Replace(fcTemp);


}

void Application::MakeEmpty()
{
	/*
	precondition: m_List�� ���ǵ� �־�� �Ѵ�
	postcondition: �迭�� ����
	*/
	m_List.MakeEmpty();
}
void Application::Run()
{
	/*
		precondition: ���̽��� �ش��ϴ� �Լ��� ���� ������־���Ѵ�
		postcondition: �Լ��� �����Ų��
	*/
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddContents();
			break;
		case 2:		//delete
			DeleteContents();
			break;
		case 3:		//replace
			ReplaceContents();
			break;
		case 4:		//search by name.
			SearchByName_SequenS();
			break;
		case 5:	//search by binary search.
			SearchByName_BinaryS();
			break;
		case 6:		//search by people.
			SearchByPeople();
			break;
		case 7:		// display all the records in list on screen.
			DisplayAllContents();
			break;
		case 8:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}

}
int Application::GetCommand()
{
	/*
	precondition: ���� ����
	postcondition: �޴��� �����ش�
	*/
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ������ �߰�" << endl;
	cout << "\t   2 : ������ ����" << endl;
	cout << "\t   3 : ������ ���ϸ��� �Է¹޾� �� ������ ġȯ (replace)" << endl;
	cout << "\t   4 : ������ ���ϸ����� ������ ã�� ���� ���" << endl;
	cout << "\t   5 : ������ ���ϸ����� ������ ã�� ���� ���(����Ž��)" << endl;
	cout << "\t   6 : Ư�� �ι��� ���Ե� ������ ã��" << endl;
	cout << "\t   7 : ��� ������ ���� ���" << endl;
	cout << "\t   8 : �� ����Ʈ�� �����" << endl;
	cout << "\t   9 : ���Ϸ� ���� �о����" << endl;
	cout << "\t   10 : ���Ͽ� ����" << endl;
	//	cout << "\t   11 : �ؽ�Ʈ ������ ������ �� ������ �ٲٱ�" << endl; 
		//���ϸ��� �Է¹޾� �ش� �������� ������ Ű����� ���� �Է¹��� �� ������ ġȯ
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::DisplayAllContents()
{
	/*
	precondition: m_List�� ���ǵ� �־���Ѵ�
	postcondition: m_List�� ���ڵ���� ���� �����ش�
	*/
	ItemType data;
	int len = m_List.GetLength();
	m_List.ResetList();
	for (int i = 0; i < len; i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
}
int Application::OpenInFile(char* fileName)
{
	/*
	precondition: fileName�� ������ �����ؾ��Ѵ�
	postcondition: ������ �������� 1 ���������� 0�� ��ȯ
	*/
	m_InFile.open(fileName);

	if (!m_InFile)	return 0;
	else	return 1;
}
int Application::OpenOutFile(char* fileName)
{
	/*
	precondition: fileName�� ������ �����ؾ��Ѵ�
	postcondition: ������ �������� 1 ���������� 0�� ��ȯ
	*/
	m_OutFile.open(fileName);
	if (!m_OutFile) return 0;
	return 1;
}
int Application::ReadDataFromFile()
{
	/*
	precondition: m_InFile�� ���ǵ� �־�� �Ѵ�. filename�� ��ġ�ϴ� ������ �־�� �Ѵ�
	postcondition: ���Ͽ��� �����͸� �а� �����ϸ� 1 �����ϸ� 0�� ��ȯ
	���ϸ��� �Է¹޾� �ش� �������� ��� ������ ���
	*/
	int index = 0;
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_InFile.eof()) {
		data.ReadDataFromFile(m_InFile);
		if (m_InFile.eof()) break;
		m_List.Add(data);
	}

	m_InFile.close();

	cout << "===================" << endl;
	DisplayAllContents();
	cout << "===========================" << endl;

	return 1;
}
int Application::WriteDataToFile()
{
	/*
	precondition: m_OutFile�� ���ǵ� �־�� �Ѵ�.
	postcondition: ���Ͽ� �����ϰ� �����ϸ� 1 �����ϸ� 0�� ��ȯ
	*/
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;


	m_List.ResetList();

	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}


	m_OutFile.close();

	return 1;
}