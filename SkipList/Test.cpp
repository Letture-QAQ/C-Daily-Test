#include <iostream>
#include <ctime>
#include <random>
using namespace std;

template<typename T>
class SkipNode {
public:
	int key;
	T value;
	vector<SkipNode*> next;

	SkipNode(int key, T value, int level);
};

template<typename T> SkipNode<T>::SkipNode(int key, T value, int level) : key(key), value(value)
{
	for (int i = 0; i < level; i++)
	{
		next.push_back(nullptr);
	}
}

template<class T>
class SkipList {
public:
	SkipNode<T>* head;

	int maxLevel;

	static const int minInt = numeric_limits<int>::min();
	static const int maxInt = numeric_limits<int>::max();

	SkipList(int maxLevel, T iniValue);

	~SkipList() {
		delete head;
		delete tail;
	}

	int randomLevel();

	SkipNode<T>* insert(int key, T value);
	SkipNode<T>* find(int key);
	SkipNode<T>* deleteNode(int key);

private:

	SkipNode<T>* tail;

	int nodeLevel(vector<SkipNode<T>*> p);
};

template<class T> SkipList<T>::SkipList(int maxLevel, T iniValue) :maxLevel(maxLevel)
{
	head = new SkipNode<T>(minInt, iniValue, maxLevel);
	tail = new SkipNode<T>(maxInt, iniValue, maxLevel);

	for (int i = 0; i < maxLevel; i++)
	{
		head->next[i] = tail;
	}
}




template<class T> int SkipList<T>::randomLevel()
{
	int random_level = 1;
	int seed = time(NULL);
	static default_random_engine e(seed);
	static uniform_int_distribution<int> u(0, 1);

	while (u(e) && random_level < maxLevel)
	{
		random_level++;
	}

	return random_level;
}

template<class T> int SkipList<T>::nodeLevel(vector<SkipNode<T>*> next)
{
	return next.size();
}

template<class T> SkipNode<T>* SkipList<T>::find(int key)
{
	SkipNode<T>* tmp = head;
	int current_level = nodeLevel(tmp->next);

	for (int i = (current_level - 1); i >= 0; i--)
	{
		while (tmp->next[i] != nullptr && tmp->next[i]->key < key)
		{
			tmp = tmp->next[i];
		}
	}
	tmp = tmp->next[0];

	if (tmp->key == key)
	{
		cout << "This key " << key << " has been found" << endl;
		return tmp;
	}
	else
	{

		return nullptr;
	}
}

template<class T> SkipNode<T>* SkipList<T>::insert(int key, T value)
{
	int x_level = randomLevel();
	SkipNode<T>* new_node = nullptr;
	SkipNode<T>* tmp = head;

	new_node = find(key);

	if (new_node) {

		new_node->value = value;
		cout << "This node " << key << " has already existed. And its value has been updated to " << value << endl;
		return head;
	}

	cout << "key: " << key << ", randomLevel: " << x_level << endl;

	new_node = new SkipNode<T>(key, value, x_level);

	for (int i = (x_level - 1); i >= 0; i--)
	{
		while (tmp->next[i] != nullptr && tmp->next[i]->key < key)
		{
			tmp = tmp->next[i];
		}

		new_node->next[i] = tmp->next[i];
		tmp->next[i] = new_node;
	}

	return head;
}

template<class T> SkipNode<T>* SkipList<T>::deleteNode(int key)
{
	SkipNode<T>* node = find(key);
	if (!node)
	{
		cout << "This deleting node" << key << "doesn't exist" << endl;
		return head;
	}
	else
	{
		SkipNode<T>* tmp = head;
		int x_level = node->next.size();

		cout << "The deleting node " << key << "'s level is " << x_level << endl;

		for (int i = (x_level - 1); i >= 0; i--)
		{
			while (tmp->next[i] != nullptr && tmp->next[i]->key < key)
			{
				tmp = tmp->next[i];
			}
			tmp->next[i] = tmp->next[i]->next[i];

			cout << "This node " << key << " has been deleted from level " << i << endl;
		}

		return head;
	}
}


int main() {
	int num_of_level = 5;//5层的跳表
	SkipList<int>list = SkipList<int>(num_of_level, 100);

	list.insert(1, 100 * 1);
	list.insert(1, 100 * 1);
	list.insert(2, 100 * 2);
	list.insert(3, 100 * 3);
	list.find(0);   // 返回 false
	list.insert(4, 100 * 4);
	list.find(1);   // 返回 true
	list.deleteNode(0);    // 返回 false，0 不在跳表中
	list.deleteNode(1);    // 返回 true
	list.find(1);   // 返回 false，1 已被擦除
}
