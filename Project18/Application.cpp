
#include "Application.h"

int Application::ReplaceFile()
{
	ReadDataFromFile();
	ReplaceContents();
	WriteDataToFile();
	return 1;
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
	return m_List.Delete(data);
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
	return m_List.Replace(data);
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
			ReplaceFile();
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
int Application::AddContents()
{
	/*
	precondition: primary key�� �ߺ��Ǹ� �ȵȴ�
	postcondition: �߰��ϰ� �����ϸ� 1 �����ϸ� 0�� ��ȯ�Ѵ�
	*/
	if (m_List.IsFull())
	{
		cout << "�� á���ϴ�" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB();
	m_List.Add(item);

	DisplayAllContents();

	return 1;
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