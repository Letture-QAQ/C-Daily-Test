#include <iostream>

using namespace std;

//声明:这里直接按照Vector实现了 如果需要按普通的数组实现会后补
template<typename T>
class Vector {
public:
	Vector() { data = new T[10]; size = 0; capacity = 10; }

	Vector(int vectorLength) {
		data = new T[vectorLength];
		size = 0;
		capacity = vectorLength;
	}

	~Vector() {
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	void Reserve(const int& newCapacity) {
		if (!newCapacity || newCapacity <= 0) {
			return;
		}

		T* tempArray = new Vector[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			tempArray[i] = data[i];
		}

		delete[] data;
		data = tempArray;
	}

	int Push(const int& insertParam) {
		if (size == capacity) {
			Reserve(capacity * 2);
		}
		data[size++] = insertParam;
	}

	void Insert(const int& insertIndex, const int& insertNum) {
		if (insertIndex > size) { return; }

		if (insertIndex == size) {
			Push(insertNum);
			return;
		}

		if (size == capacity) {
			Reserve(capacity * 2);
		}
		for (int i = size; i >= 0; i--) {
			if (size == insertIndex) {
				data[size] = insertNum;
			}
			else {
				data[size] = data[size - 1];
			}
		}
		size++;
	}

	void Remove(const int& removeIndex) {
		int tempNum = 0;
		T* tempArray = new Vector[size - 1];
		for (int i = 0; i < size; i++) {
			if (i == removeIndex - 1) {
				tempArray[i] = data[i++];
				size--;
			}
			else {
				tempArray[i] = data[i];
			}
		}
		delete[] data;
		data = tempArray;
	}

	int pop() {
		if (--size < capacity / 2) {
			Reserve(capacity / 2);
		}
		return data[--size]
		//int tempNum = data[size];
		//delete data[--size]
		//return tempNum;
	}

	void clear() {
		delete[] data;
		data = new T[10];
		size = 0;
		capacity = 10;
	}

	int findIndex(const int& num) {
		for (int i = 0; i < size; i++) {
			if (data[i] == num) {
				return i;
			}
		}

		return -1;
	}
private:
	T* data;
	int size;
	int capacity;
};