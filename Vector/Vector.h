#include <iostream>
using namespace std;
template<typename T>
class Vector {
public:
	typedef T value_type;
	typedef T* iterator;

public:
	Vector() { data = nullptr; size = 0; capacity = 0;}
	Vector(int vectorLength) {
		data = new T[vectorLength];
		size = vectorLength;
		capacity = vectorLength;
	}
	Vector(const Vector& vector) {
		size = vector.size;
		capacity = vector.capacity;
		data = new value_type[capacity];
		for (int i = 0; i < size; ++i) {
			data[i] = vec.data[i];
		}
	}
	~Vector() {
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}

private:
	value_type* data;
	size_t size;
	size_t capacity;	//vector×Ô¶¯À©ÈÝ
};