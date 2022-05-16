#include <iostream>

template <class T>
class DoubleLinkList;

template <class T>
class Node {
public:
	friend class DoubleLinkList<T>;

	T data;
	Node<T>* pLast;
	Node<T>* pNext;
public:
	Node(const T& data) {
		this->data = data;
		this->pLast = nullptr;
		this->pNext = nullptr;
	}
};

template <class T>
class DoubleLinkList {
public:
	DoubleLinkList() {
		this->pHead = nullptr;
		this->length = 0;
	}

	~DoubleLinkList() {
		Node<T>* pTemp = this->pHead;
		Node<T>* pNode = pTemp;
		for (; pTemp != nullptr && pTemp->pNext != nullptr;)
		{
			pTemp = pTemp->pNext;
			delete pNode;
			pNode = pTemp;
		}

	}

	bool isEmpty() {
		if (this->pHead == nullptr) return true;
		return false;
	}

	int listLength() {
		return this->length;
	}

	Node<T>* push(const T& data) {
		if (this->isEmpty()) {
			this->pHead = new Node<T>(data);
			this->length++;
			return this->pHead;
		}
		else {
			Node<T>* pTemp = this->pHead;
			while (pTemp->pNext != nullptr) {
				pTemp = pTemp->pNext;
			}
			pTemp->pNext = new Node<T>(data);
			pTemp->pNext->pLast = pTemp;
			this->length++;
			return pTemp->pNext;
		}
	}

	Node<T>* insert(Node<T>* curNode, const int& index) {
		//没有的话直接创建新的
		if (this->isEmpty() || index > this->listLength()) {
			this->push(curNode->data);
			return this->pHead;
		}

		Node<T>* pTemp = this->pHead;
		int tempIndex = index;
		while (--tempIndex > 0) {
			pTemp = pTemp->pNext;
		}
		curNode->pNext = pTemp->pNext;
		curNode->pLast = pTemp;
		if (pTemp->pNext != nullptr) {
			pTemp->pNext->pLast = curNode;
		}
		pTemp->pNext = curNode;

		return this->pHead;
	}

	Node<T>* find(const int& index) {
		int curIndex = index;
		Node<T>* pTemp = this->pHead;

		while (--curIndex > 0) {
			pTemp = pTemp->pNext;
		}

		return pTemp;
	}

	void remove(const Node<T>* curNode) {
		for (Node<T>* pTemp = this->pHead; pTemp->pNext != nullptr; pTemp = pTemp->pNext)
			if (pTemp == curNode)
			{
				if (pTemp->pNext == nullptr) {

				}
				Node<T>* pNode = pTemp;
				pNode->pNext->pLast = pNode->pLast;
				pNode->pLast->pNext = pNode->pNext;
				pNode->pLast = nullptr;
				pNode->pNext = nullptr;
				delete pTemp;
				delete pNode;
				break;
			}
	}

	void popAll() {
		Node<T>* pTemp = this->pHead;
		Node<T>* pNode;
		pNode = pTemp;
		while (pTemp != nullptr) {
			pTemp = pTemp->pNext;
			delete pNode;
			pNode = pTemp;
		}

		this->length = 0;
		this->pHead = nullptr;
	}
private:
	Node<T>* pHead;
	int length;
};