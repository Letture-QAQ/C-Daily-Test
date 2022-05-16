#include "DoubleLinkList.h"

using namespace std;

int main() {
	DoubleLinkList<int> list1;
	//auto list1 = new DoubleLinkList();	//¶î Ê²Ã´Çé¿ö£¡
	auto node1 = list1.push(1);
	auto node2 = list1.push(3);
	//auto node3 = new Node<int>(3);
	auto node3 = list1.insert(node1, 3);
	auto ret = list1.find(2);
	//list1.remove(node2);
	list1.popAll();
	return 0;
}