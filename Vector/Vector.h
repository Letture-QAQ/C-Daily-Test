#include <iostream>
using namespace std;
template<typename T>
class Vector {
public:
	typedef T value_type;
	typedef T* iterator;

public:
	Vector() {

	}

private:
	value_type* _data;
	size_t _size;
	size_t _capacity;	//vector×Ô¶¯À©ÈÝ
};