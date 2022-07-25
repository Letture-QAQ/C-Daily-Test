#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

struct SkipListNode
{
	SkipListNode(int int_NodeData, int int_NodeLevel);

	int int_CurData;
	std::vector<SkipListNode*> p_Forward;
};

class SkipList {
public:
	//	Construct function
	SkipList();
	~SkipList();

	//	Requirement function
	bool search(int int_TargetNode);
	void add(int int_NodeData);
	bool erase(int int_NodeData);

	//	Tool function
	void print();
	bool isEmpty();

private:
	SkipListNode* p_Head;
	int int_Count;
	int int_Level;

};

//	Rand a number
int getRandLevel()
{
	int int_Level = 1;
	while (rand() % 2 == 1)
		++int_Level;

	return int_Level;
}

SkipListNode::SkipListNode(int int_NodeData, int int_NodeLevel)
	: int_CurData(int_NodeData)
	, p_Forward(int_NodeLevel)
{

}

SkipList::SkipList():p_Head(nullptr), int_Count(0), int_Level(1)
{
	auto pHead = new SkipListNode(INT_MIN, int_Level);
	p_Head = pHead;
}

SkipList::~SkipList()
{
	auto* pNode = p_Head;
	while (pNode != nullptr) {
		auto pNext = pNode->p_Forward[0];
		delete pNode;
		pNode = pNext;
	}
}

bool SkipList::search(int inInt_TargetData)
{
	if ( isEmpty() )
		return false;

	auto pTemp = p_Head;
}

bool SkipList::isEmpty()
{
	return int_Count == 0;
}

void SkipList::print()
{
	auto* pTemp = p_Head;
	while (pTemp != nullptr) {
		if (pTemp->int_CurData >= 0) {
			std::cout << "curData is :" << pTemp->int_CurData << " , Level is :" << int(pTemp->p_Forward.size()) << std::endl;
		}
		pTemp = pTemp->p_Forward[0];
	}
}

void SkipList::add(int int_NodeData)
{
	//	视为第一次插入,同时只处理第一次插入
	if (int_Count == 0) {
		int int_CurLevel = getRandLevel();
		if (int_CurLevel > int_Level) {
			int_CurLevel = ++int_Level;
			p_Head->p_Forward.resize(int_Level);
		}
		auto pNode = new SkipListNode(int_NodeData, int_CurLevel);

		for (int int_TempLevel = int_Level - 1; int_TempLevel >= 0; --int_TempLevel) {
			p_Head->p_Forward[int_TempLevel] = pNode;
			pNode->p_Forward[int_TempLevel] = nullptr;
		}

		++int_Count;
		return;
	}
	
	//	正常插入
	auto pNode = p_Head;
	std::vector<SkipListNode*> vec_Data(int_Level);

	for (int int_TempLevel = int_Level - 1; int_TempLevel >= 0; --int_TempLevel) {
		if (pNode->p_Forward[int_TempLevel] == nullptr) {
			vec_Data[int_TempLevel] = pNode;
			continue;
		}

		while (pNode->p_Forward[int_TempLevel]->int_CurData < int_NodeData) {
			pNode = pNode->p_Forward[int_TempLevel];
			if (pNode->p_Forward[int_TempLevel] == nullptr)
				break;
		}

		vec_Data[int_TempLevel] = pNode;
	}

	if ((pNode->p_Forward[0] != nullptr) && (pNode->p_Forward[0]->int_CurData == int_NodeData))
		return;

	int int_TempLevel = getRandLevel();
	if (int_TempLevel > int_Level) {

		int_TempLevel = ++int_Level;

		vec_Data.resize(int_Level);
		vec_Data[int_Level - 1] = p_Head;

		p_Head->p_Forward.resize(int_Level);
	}

	auto* pTemp = new SkipListNode(int_NodeData, int_TempLevel);
	for (int int_CurLevel = int_TempLevel - 1; int_CurLevel >= 0; --int_CurLevel) {
		p_Head->p_Forward[int_CurLevel] = vec_Data[int_CurLevel]->p_Forward[int_CurLevel];
		vec_Data[int_CurLevel]->p_Forward[int_CurLevel] = pTemp;
	}

	++int_Count;
}

bool SkipList::erase(int int_NodeData)
{
	auto* pNode = p_Head;
	if (isEmpty())
		return false;

	std::vector<SkipListNode*> vec_Data(int_Level);
	for (int int_CurLevel = int_Level - 1; int_CurLevel >= 0; --int_CurLevel) {
		if (nullptr == pNode->p_Forward[int_CurLevel]) {
			vec_Data[int_CurLevel] = pNode;
			continue;
		}

		while (pNode->p_Forward[int_CurLevel]->int_CurData < int_NodeData) {
			pNode = pNode->p_Forward[int_CurLevel];
			if (pNode->p_Forward[int_CurLevel] == nullptr)
				break;
		}

		vec_Data[int_CurLevel] = pNode;
	}

	if (pNode->p_Forward[0]->int_CurData != int_NodeData) {
		return false;
	}

	auto* pRemove = pNode->p_Forward[0];
	for (int int_CurLevel = int_Level - 1; int_CurLevel >= 0; --int_CurLevel) {
		if (vec_Data[int_CurLevel]->p_Forward[int_CurLevel] == pRemove)
			vec_Data[int_CurLevel]->p_Forward[int_CurLevel] = pRemove->p_Forward[int_CurLevel];
	}

	for (int int_CurLevel = int_Level - 1; int_CurLevel >= 0; --int_CurLevel) {
		if (p_Head->p_Forward[int_CurLevel] == nullptr)
			--int_Level;
	}

	p_Head->p_Forward.resize(int_Level + 1);
	--int_Count;
}