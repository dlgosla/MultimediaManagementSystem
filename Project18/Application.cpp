#include "Application.h"
#include "ItemType.h"
#include "SortedList.h"

void Application::printAllEvent()
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
	* pre:�̺�Ʈ ���� �̺�Ʈ ����Ʈ�� ����� ��
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


void Application::FindNDisplayEvent() //�̺�Ʈ �̸��� �Է¹޾Ƽ� �ű� �Ҽӵ� �������� �ڼ��� ������ ���
{
	string eName;
	cout << "������ ������ �� �̺�Ʈ ���� �Է��ϼ���: ";
	cin >> eName;

	Event temp;
	temp.setRecord(eName);
	eventList.Get(temp);
	cout << "========�̺�Ʈ " << eName << "�� ������========" << endl;
	temp.printRecord(m_List);
	cout << "============================" << endl;
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
		unsortedFC.Add(temp);
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
	unsortedFC.Delete(temp);
}

void Application::Display_FC_list() //FC_list�� ����ִ� ������ ȭ�鿡 ���
{
	fc_list.DisplayRecord();
}


void Application::Display_Detail_FC()// Ư�� FC�� �ڼ��� ����(master list�� ����� ����)�� ȭ�鿡 ���
{
	string name;
	cout << "FC�� �ڼ��� ������ ����ϴ� �Լ��Դϴ� ";
	SearchByName_BinaryS();
}

void Application::runFC()
{
	while (1) {
		cout << "=======================" << endl;
		cout << "1. Add_FC " << endl;
		cout << "2. Delete_FC: " << endl;
		cout << "3.Display_FC_list" << endl;
		cout << "4. Display_Detail_FC: " << endl;
		cout << "5. Rearrange_FC" << endl;
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
			Rearrange_FC();
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
		cout << "�̿��� ����:exit" << endl;
		cout << "=========================" << endl;

		int command;
		cout << ">> ";
		cin >> command;

		switch(command)
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
		default:
			return;
			break;
		}
	}
}


void Application::Rearrange_FC() //Ű����κ��� ������ �Է¹޾Ƽ� FC�� ���� ����(���� ��, �̸� ��, ���ֺ��� ��, ��)�� �ٲ۴�.
{

	while (1) {
		cout << "���� ������ �Է��ϼ���: " << endl;
		cout << "1. �̸���" << endl;
		cout << "2. ���� ��" << endl;
		cout << "3. ���ֺ��� ��" << endl;
		int command;
		cout << ">>";
		cin >> command;

		switch (command)
		{
		case 1:
			cout << "�̸� �� " << endl;
			fc_list.DisplayRecord();
			break;

		case 2:
			cout << " ���� ��" << endl;
			unsortedFC.DisplayRecord();
			break;
		case 3:
			cout << "���ֺ��� �� " << endl;
			unsortedFC.DisplayRecord();
			break;
		default:
			return;
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
	m_List.Retrieve_SeqS(data);

	EventType eItem;
	eItem.SetName(data.GetName());

	// �̺�Ʈ����Ʈ���� ����
	Event e;
	e.setRecord(data.GetEvent());
	eventList.Get(e);
	e.Delete(eItem);
	eventList.Replace(e);

	if (e.getCountOfEvent() == 0)
	{
		eventList.Delete(e);
	}

	int result = m_List.Delete(data); //�����͸���Ʈ���� ����

	//fc����Ʈ���� ����
	FC temp;
	temp.setRecord(data.GetName());
	fc_list.Delete(temp);

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

	/*
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
	*/
	
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
		case 11:
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
	cout << "\t   11 : �ؽ�Ʈ ������ ������ �� ������ �ٲٱ�" << endl; 
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