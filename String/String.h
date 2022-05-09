#pragma once
#include <iostream>

class CustomString {
public:
	CustomString(const char* string);	//���캯��
	CustomString(const CustomString &string);	//��������
	~CustomString();	//��������
	CustomString substr(int index, int length);
	CustomString append(const char* string);
	void operator= (const char* string);
	bool operator== (CustomString &string);
	friend istream &operator>>(istream &in_string, CustomString &string);
	friend ostream &operator<<(ostream &out_string, CustomString &string);

	//���캯��
	CustomString(const char* string) {
		if (string == nullptr) {
			std::cout << "�����˿��ַ���" << std::endl;
		}
		stringArray = string;
		setStringLength();
		std::cout << stringLength << std::endl;
	}

	//�������캯��
	CustomString(const CustomString &string) {
		if (string.stringArray == nullptr) {
			return;
		}
		stringArray = string.stringArray;
	}

	//��������
	~CustomString() {
		stringArray = nullptr;
		stringLength = NULL;
	}

	//��ȡ�ַ���
	CustomString substr(int index, int length) {
		char* subString = nullptr;
		const char* string = this->getArray();
		for (int startIndex = 0; startIndex < length; startIndex++) {
			subString[startIndex] = string[index + startIndex];
		}
		return subString;
	}

	CustomString append(const char* string) {
		char* localString = new char[1005];
		const char* strArray = this->getArray();
		strcpy(localString, strArray);
		int stringLength = this->getStringLength();
		for (int index = 0; string[index] != '\0'; index++) {
			localString[stringLength + index] = string[index];
		}
		const char* tempString = localString;
		CustomString(tempString);
	}

	//���� = �����
	void operator= (const char* string) {
		stringArray = string;
	}

	//���� == �����
	bool operator== (CustomString &string1) {
		const char* string_1 = this->getArray();
		const char* string_2 = string1.getArray();
		int index = 0;
		int sameNum = 0;
		for (; index < this->getStringLength(); index++) {
			if (string_1[index] != string_2[index]) {
				break;
			}
			if (index == this->getStringLength()) {
				return true;
			}
		}
		return false;
	}

	//���� >> �����
	friend istream &operator>> (istream &in_string, CustomString &string){
		in_string >> string.getArray();
		return in_string;
	}

	//���� << �����
	friend ostream &operator<< (ostream &out_string, CustomString &string) {
		out_string << string.getArray();
		return out_string;
	}

	// ====================== ���ܺ��� ===================
	const char* getArray() {
		return stringArray;
	}

	void setStringLength() {
		int index = 0;
		for (; stringArray[index] != '\0'; index++)
		stringLength = index + 1;
	}

	int getStringLength() {
		return stringLength;
	}
private:
	const char* stringArray;
	int stringLength;
};