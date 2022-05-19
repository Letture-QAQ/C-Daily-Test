#include <iostream>
#include <time.h>

#define DEFAULT_RINGBUFFER_SIZE 256

class RingBuffer {
public:
	RingBuffer() {
		this->size = 0;
		this->capacity = 0;
		this->data = nullptr;
		this->head = nullptr;
		this->tail = nullptr;
	}

	RingBuffer(int bufferSize) {
		this->size = 0;
		this->capacity = bufferSize;
		this->data = new char[bufferSize];
		this->head = nullptr;
		this->tail = nullptr;
	}

	~RingBuffer() {
		this->size = 0;
		this->capacity = 0;
		this->head = nullptr;
		this->tail = nullptr;

		delete[] data;
	}

	void reserve(int newSize) {
		if (this->data == nullptr) {
			char* tempData = new char[newSize];
			memcpy(tempData, data, newSize);
			delete[] data;

			this->data = tempData;
			this->capacity = newSize;
			this->head = data;
			this->tail = data + size;
		}
		else
		{
			data = new char[newSize];
		}
	}

	void push(const char* inData) {
		if (inData == nullptr) return;

		int dataLength = strlen(inData);
		if (dataLength <= 0) return;

		this->capacityIncrease(dataLength);
		this->size = this->size + dataLength;

		for (int i = 0;i < dataLength;i++){
		}
	}

	void pop(char* inData, int inDataLength) {

		this->capacityConserve();
	}

	void capacityConserve() {
		int tempCapacity = capacity / 2;
		while (size < tempCapacity) {
			tempCapacity = tempCapacity / 2;
		}
		this->reserve(tempCapacity);
	}

	void capacityIncrease(int inDataLength) {
		if (this->size + inDataLength >= capacity) {
			this->reserve(capacity * 2);
		}
	}

	void print() {
		if (data == nullptr)
		{
			std::cout << "empty Ring !" << std::endl;
			return;
		}
		std::cout << "===========================" << std::endl;
		for (int i = 0; i < size; ++i)
			std::cout << *(data + i);

		std::cout << std::endl;

		std::cout << "head Ptr Data :" << *head << std::endl;
		std::cout << "tail Ptr Data :" << *tail << std::endl;
		std::cout << "current capacity = " << capacity << std::endl;
		std::cout << "current count = " << size << std::endl;
		std::cout << "===========================" << std::endl;
	}
private:
	int size;	//当前内容大小
	int capacity;	//当前容量

	char* head;
	char* tail;
	char* data;
};