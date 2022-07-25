#include "SkipList.h"


int main()
{
	SkipList* skiplist = new SkipList();
	skiplist->add(1);
	skiplist->add(1);
	skiplist->add(2);
	skiplist->add(3);
	skiplist->search(0);   // 返回 false
	skiplist->add(4);
	skiplist->search(1);   // 返回 true
	skiplist->erase(0);    // 返回 false，0 不在跳表中
	skiplist->erase(1);    // 返回 true
	skiplist->search(1);   // 返回 false，1 已被擦除
}