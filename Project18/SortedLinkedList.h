#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

template <typename T>
struct NodeType
{
	T data;	///����� ������ Ÿ��
	NodeType* next;	///���� �����͸� ����Ű�� ������
};

template <typename T>
class SortedLinkedList
{
public:
	/**
	*	������
	*/
	SortedLinkedList();

	/**
	*	�Ҹ���
	*/
	~SortedLinkedList();

	/**
	*	@brief	�� ����Ʈ�� �����
	*	@pre	����
	*	@post	�� ����Ʈ�� ����
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� �����Ѵ�
	*	@pre	����
	*	@post	����Ʈ�� ���̸� �����Ѵ�
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� item�� �߰��Ѵ�
	*	@pre	����Ʈ�� �� ������ �ʰ� �ߺ�Ű�� ������ �ȵȴ�
	*	@post	����Ʈ�� item�� �߰��ϰ� �����ϸ� 1, �����ϸ� 0�� ���� 
	*/
	int Add(T item);

	/**
	*	@brief	����Ʈ���� item�� �����Ѵ�
	*	@pre	����Ʈ�� ������� �ʰ�, ����Ʈ �ȿ� item�� Ű�� �־���Ѵ�
	*	@post	����Ʈ���� item�� �����ϰ� ���� �� 1, ���н� 0 ����
	*/
	int Delete(T item);

	/**
	*	@brief	item�� Ű�� ��ġ�ϴ� �����͸� ã�� item���� ġȯ�Ѵ�
	*	@pre	����Ʈ�� ������� �ʰ�, ����Ʈ �ȿ� item�� Ű�� �־���Ѵ�
	*	@post	�����Ͱ� �ٲ�� ������ 1, ���н� 0 ����
	*/
	int Replace(T item);

	/**
	*	@brief item�� Ű�� ��ġ�ϴ� �����͸� ã�� item�� �����Ѵ�
	*	@pre	Ű ���� �־�� �Ѵ�
	*	@post	item�� Ű�� ��ġ�ϴ� �����͸� ã�� item�� �����Ѵ� ������ 1 , ���н� 0 ����
.
	*/
	int Get(T& item);

	/**
	*	@brief	����Ʈ�� iterlator�� �ʱ�ȭ�Ѵ�
	*	@pre	����
	*	@post	����Ʈ�� iterlator�� �ʱ�ȭ�Ѵ�
	*/
	void ResetList();

	/**
	*	@brief	���� �������� item�� �����Ѵ�
	*	@pre	curPointer �� ���ǵ� �־���Ѵ�
	*	@post	���� �������� item�� �����Ѵ�
	*/
	void GetNextItem(T& item);

private:
	NodeType<T>* m_pList;	///ù��° ��带 ����Ű�� ������
	NodeType<T>* m_pCurPointer;	///���� ��ġ�� ����Ű�� ������
	int m_nLength;	///���� ����� ����
};


// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::Add(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			if (m_pCurPointer->data == node->data)
			{
				return 0;
			}

			if (m_pCurPointer->data > node->data)
			{
				if (pre == NULL)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}	//���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}

		}
	}

	m_nLength++;

	return 1;
}

//Delete item from this list.
template <typename T>
int SortedLinkedList<T>::Delete(T item)
{
	bool moreToSearch, found;
	NodeType<T>* pre = NULL;	//���� ����

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == m_pCurPointer->data)	//���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
		{
			found = true;	//ã�����Ƿ� found �� ����
			if (pre == NULL)
				m_pList = m_pCurPointer->next;	//�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
			m_nLength--;	//����Ʈ�� ���̸� 1 �ٿ��ش�.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}

//Change value of item which is in this list.
template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//���� �ʱ�ȭ

	while (moreToSearch && !found)	//����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;	//ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}


#endif	// LINKED_LIST