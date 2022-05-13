#include <iostream>

typedef struct DoubleLinkListNode {
	struct DLNode *pLast;
	struct DLNode *pNext;
	int data;
}DLNode, *DLinkList;

template<typename T>
class DoubleLinkList {

};