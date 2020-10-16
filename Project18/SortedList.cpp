#include "SortedList.h"




int SortedList::Retrieve_SeqS(ItemType& data)
{
	/*
	* pre: data�� ��ġ�ϴ� ���� m_Array�� �־�� �Ѵ�
	* post: ������ 1 ���н� 0��ȯ
	*/
	ItemType CurItem;

	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while (m_CurPointer < m_Length)	//ó������ ������
	{
		switch (CurItem.CompareByName(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data = CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� Primary key�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� Primary key�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

int SortedList::Retrieve_BinaryS(ItemType& data)
{
	/*
	* pre: m_Array�� ���ǵ� �־�� �Ѵ�
	* post: �����˻� �� �Ȱ��� �� ã���� data�� �ش� ������ �����ϰ� ������ 1 ���н� 0 ��ȯ 
	*/
	ItemType CurItem;

	if (m_Length == 0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos = m_Length / 2;	//�迭�� �߰����� ����
	while (1)
	{
		switch (m_Array[currentPos].CompareByName(data))
		{
		case EQUAL:	//���� �����۰� �Է� �������� Primary key�� ��ġ�Ѵٸ�
			data = m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� Primary key�� �Է� �������� Primary key���� ũ�ٸ�
			if (currentPos == 0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� Primary key�� �Է� �������� Primary key���� �۴ٸ�
			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}

bool SortedList::IsEmpty()
{
	/*
		precondition: m_Array�� ���ǵ� �־����
		postcondition: �迭�� ������� true, �Ⱥ������ false�� ����
	*/

	if (m_Length == 0)
		return true; //�����
	return false; //�Ⱥ����
}

int SortedList::Delete(ItemType data)
{
	/*
		precondition: m_Array�� data�� �־�� �Ѵ�
		postcondition: m_Array���� data�� ��ġ�ϴ� ���� ã�� ����
					   �����ϸ� 1, �����ϸ� 0�� ��ȯ
	*/
	if (IsEmpty())
		return 0;

	if (Retrieve_SeqS(data))	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}
int SortedList::Replace(ItemType data)
{
	/*
		precondition: m_Array�� data�� �־���Ѵ�.
		postcondition: �Էµ� data�� ������ ����� ã�� �ش� ����� data�� ġȯ�Ѵ�
					   �����ϸ� 1, �����ϸ� 0�� ��ȯ
	*/
	ItemType tmp(data);

	if (Retrieve_SeqS(data))
	{
		m_Array[m_CurPointer] = tmp;
		return 1;
	}
	return 0;
}

void SortedList::MakeEmpty()
{
	/*
		precondition: m_Array�� ���ǵ��־���Ѵ�
		postcondition: m_Length�� 0���� �����ؼ� �󸮽�Ʈ�� �����
	*/
	m_Length = 0; //����Ʈ�� ����� ���ڵ� ��
}


int SortedList::GetLength()
{
	/*
		precondition: m_Array�� ���ǵ��־���Ѵ�
		postcondition: m_Length�� ��ȯ�Ѵ�
	*/
	return m_Length;
}


bool SortedList::IsFull()
{
	/*
		precondition: m_Array�� ���ǵ��־���Ѵ�
		postcondition: ��á���� true, �ƴϸ� false�� �����Ѵ�
	*/
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


int SortedList::Add(ItemType data)
{
	/*
	precondition: m_Array�� ���ǵ��־���Ѵ�, data�� m_Array�� ����� �Ѵ�
	postcondition: �� �ڿ� data�� �߰��ϰ� �����ϸ� 1, �����ϸ� 0�� ��ȯ
	*/
	
	if (IsFull()) return 0;
	if (m_Length == 0) {   
		m_Array[m_Length++] = data;
		return 1;
	}
	
	int iPos = 0;
	bool found = false;
	ItemType curItem;
	ResetList();
	iPos = GetNextItem(curItem);  

	while (iPos > -1 && !found)
	{
		switch (curItem.CompareByName(data))
		{
		case EQUAL:
			cout << " %%% �����ʹ� �ߺ��� �� �����ϴ� %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos = GetNextItem(curItem);
			break;
		}
	}

	if (iPos == -1) {
		m_Array[m_Length++] = data;
		return 1;
	}

	for (int i = m_Length; i > iPos; i--) {
		m_Array[i] = m_Array[i - 1];
	}

	m_Array[iPos] = data;

	m_Length++;
	return 1;

}


void SortedList::ResetList()
{
	/*
		precondition: m_CurPointer�� ���ǵ��־�� �Ѵ�
		postcondition: m_CurPointer �� -1�� �����Ѵ�
	*/
	m_CurPointer = -1;
}


int SortedList::GetNextItem(ItemType& data)
{
	/*
	precondition: m_Array�� ���ǵ� �־�� �Ѵ�
	postcondition: data�� m_CurPointer��ġ�� �����ϰ� m_CurPointer�� ��ȯ, ���н� -1��ȯ
	*/
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) {
		return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}