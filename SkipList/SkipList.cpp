#include "SkipList.h"


int main()
{
	SkipList* skiplist = new SkipList();
	skiplist->add(1);
	skiplist->add(1);
	skiplist->add(2);
	skiplist->add(3);
	skiplist->search(0);   // ���� false
	skiplist->add(4);
	skiplist->search(1);   // ���� true
	skiplist->erase(0);    // ���� false��0 ����������
	skiplist->erase(1);    // ���� true
	skiplist->search(1);   // ���� false��1 �ѱ�����
}