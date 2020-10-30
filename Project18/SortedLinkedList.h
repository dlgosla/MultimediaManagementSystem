#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

template <typename T>
struct NodeType
{
	T data;	///저장될 데이터 타입
	NodeType* next;	///다음 데이터를 가리키는 포인터
};

template <typename T>
class SortedLinkedList
{
public:
	/**
	*	생성자
	*/
	SortedLinkedList();

	/**
	*	소멸자
	*/
	~SortedLinkedList();

	/**
	*	@brief	빈 리스트로 만든다
	*	@pre	없음
	*	@post	빈 리스트로 만듦
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 리턴한다
	*	@pre	없음
	*	@post	리스트의 길이를 리턴한다
	*/
	int GetLength() const;

	/**
	*	@brief	리스트에 item을 추가한다
	*	@pre	리스트가 꽉 차있지 않고 중복키가 있으면 안된다
	*	@post	리스트에 item을 추가하고 성공하면 1, 실패하면 0을 리턴 
	*/
	int Add(T item);

	/**
	*	@brief	리스트에서 item을 삭제한다
	*	@pre	리스트가 비어있지 않고, 리스트 안에 item의 키가 있어야한다
	*	@post	리스트에서 item을 삭제하고 성공 시 1, 실패시 0 리턴
	*/
	int Delete(T item);

	/**
	*	@brief	item의 키와 일치하는 데이터를 찾아 item으로 치환한다
	*	@pre	리스트가 비어있지 않고, 리스트 안에 item의 키가 있어야한다
	*	@post	데이터가 바뀐다 성공시 1, 실패시 0 리턴
	*/
	int Replace(T item);

	/**
	*	@brief item의 키와 일치하는 데이터를 찾아 item에 복사한다
	*	@pre	키 값이 있어야 한다
	*	@post	item의 키와 일치하는 데이터를 찾아 item에 복사한다 성공시 1 , 실패시 0 리턴
.
	*/
	int Get(T& item);

	/**
	*	@brief	리스트의 iterlator를 초기화한다
	*	@pre	없다
	*	@post	리스트의 iterlator를 초기화한다
	*/
	void ResetList();

	/**
	*	@brief	다음 아이템을 item에 복사한다
	*	@pre	curPointer 가 정의돼 있어야한다
	*	@post	다음 아이템을 item에 복사한다
	*/
	void GetNextItem(T& item);

private:
	NodeType<T>* m_pList;	///첫번째 노드를 가리키는 포인터
	NodeType<T>* m_pCurPointer;	///현재 위치를 가리키는 포인터
	int m_nLength;	///현재 노드의 개수
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
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
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
				}	//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}	//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	NodeType<T>* pre = NULL;	//변수 선언

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == m_pCurPointer->data)	//현재 가리키는 원소의 값과 item의 값이 일치할 때
		{
			found = true;	//찾았으므로 found 값 변경
			if (pre == NULL)
				m_pList = m_pCurPointer->next;	//항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	//이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
			m_nLength--;	//리스트의 길이를 1 줄여준다.
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);
		}	//일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
	}

	if (found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.
}

//Change value of item which is in this list.
template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);	//변수 초기화

	while (moreToSearch && !found)	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}


#endif	// LINKED_LIST