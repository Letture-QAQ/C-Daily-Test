#include <iostream>
#include <time.h>

#define DEFAULT_RINGBUFFER_SIZE 256

class RingBuffer {
public:
	RingBuffer() {
		this->size = 0;
		this->capacity = DEFAULT_RINGBUFFER_SIZE;
		this->data = new char[DEFAULT_RINGBUFFER_SIZE];
		this->head = 0;
		this->tail = 0;
	}

	RingBuffer(int bufferSize) {
		this->size = size;
		this->capacity = bufferSize;
		this->data = new char[bufferSize];
		this->head = head;
		this->tail = head + size;
	}

	~RingBuffer() {
		this->size = 0;
		this->capacity = 0;
		this->data = nullptr;
		this->head = 0;
		this->tail = 0;
	}

	void reserve(int newSize) {

	}

	void push(const char* inData,int inDataLength) {
		
	}

	void pop(char* inData, int inDataLength) {

	}

	void capacityModify() {
		if (size < capacity / 2) {
			this->reserve(capacity / 2);
		}
		else if(size >= capacity)
		{
			this->reserve(capacity * 2);
		}
	}

	void capacityModify(int inDataLength) {
		if (size - inDataLength)
		if (size > capacity) {

		}
		else {

		}
	}
private:
	int size;
	int capacity;
	int head;
	int tail;
	char* data;
};