#include <iostream>
using namespace std;
class CustomString {
public:
	//CustomString(const char* string);	//���캯��
	//CustomString(const CustomString &string);	//��������
	//~CustomString();	//��������
	//CustomString substr(int index, int length);
	//CustomString append(const char* string);
	//CustomString* split(const char* splitString);
	//int find(const char* targetString);
	//void operator= (const char* string);
	//bool operator== (CustomString &string);
	//friend istream &operator>>(istream &in_string, CustomString &string);
	//friend ostream &operator<<(ostream &out_string, CustomString &string);

	//Ĭ�Ϲ��캯��
	CustomString(){}

	//���캯��
	CustomString (const char* string) {
		if (string == nullptr) {
			std::cout << "�����˿��ַ���,�޷����й���" << std::endl;
		}
		stringArray = string;
		setStringLength();
		std::cout << stringArray << std::endl;
		std::cout << stringLength << std::endl;
	}

	//�������캯��
	CustomString(const CustomString &string) {
		if (string.stringArray == nullptr) {
			std::cout << "�����˿��ַ���,�޷����п���" << std::endl;
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
		int stringLength = this->getStringLength();
		char* subString = new char[length];
		const char* string = this->getArray();
		for (int startIndex = 0; startIndex < length; startIndex++) {
			subString[startIndex] = string[index + startIndex];
		}
		return subString;
	}

	//ƴ���ַ���
	CustomString append(const char* string) {
		const char* strArray = this->getArray();
		int stringLength = this->getStringLength();

		int cinStringLength = getStringLength(string);
		char* localString = new char[stringLength + cinStringLength];
		for (int i = 0; i < stringLength; i++) {
			localString[i] = strArray[i];
		}
		for (int index = 0; string[index] != '\0'; index++) {
			localString[stringLength + index] = string[index];
		}
		stringArray = localString;
		return stringArray;
	}

	//�����ַ���
	int find(const char* targetString) {
		if (targetString == nullptr) {
			return 0;
		}
		int targetStringLength = 0;
		for (int i = 0; targetString[i] != '\0'; i++)
			targetStringLength++;

		int targetStringNum = 0;
		int stringLength = this->getStringLength();
		const char* strArray = this->getArray();
		for (int index = 0; strArray[index] != '\0'; index++) {
			if (strArray[index] == targetString[0]) {
				int targetWordNum = 0;
				for (int otherIndex = 0; otherIndex < targetStringLength; otherIndex++) {
					if (strArray[otherIndex] == targetString[otherIndex]) {
						targetWordNum++;
					}
				}
				if (targetWordNum == targetStringLength)
					targetStringNum++;
			}
		}
		return targetStringNum;
	}

	//�ָ��ַ���
	CustomString* split(const char* splitString) {
		int splitNum = 0;
		const char* string = this->getArray();

		int array[10] = {};
		for (int i = 0; string[i] != '\0'; i++) {
			char curString = (char)splitString;
			if (string[i] == curString) {
				splitNum++;
				array[splitNum] = i;
			}
		}
		CustomString* splitedString = new CustomString[splitNum];

		int head = 0;
		int stringLength = this->getStringLength();
		while (head != splitNum) {
			int curStringLength = array[head + 1] - array[head];
			char* curString = new char[curStringLength];
			for (int i = 0; i < curStringLength; i++) {
				curString[i] = string[array[head] + i];
			}
			splitedString[head] = curString;
		}

		return splitedString;
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
		int stringLength = this->getStringLength();
		for (; index < stringLength; index++) {
			if (string_1[index] != string_2[index]) {
				break;
			}
			if (index == stringLength) {
				return true;
			}
		}
		return false;
	}

	//���� >> �����
	//friend istream &operator>> (istream &in_string, CustomString &string){
	//	in_string >> string.getArray();
	//	return in_string;
	//}

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

	int getStringLength(const char* string) {
		if (string == nullptr)
			return 0;

		int stringLength = 0;
		for (int i = 0; string[i] != '\0'; i++)
			stringLength++;

		return stringLength;
	}
private:
	const char* stringArray = nullptr;
	int stringLength;
};