#include "String.h"

int main()
{
	auto str1 = CustomString("test1");
	auto str2 = CustomString("test2, test3");
	str1 = "test3";

	int len = str1.getStringLength();
	std::cout << len << std::endl;

	CustomString sub1 = str1.substr(1, 2);
	str1.append("append");
	bool equal = str1 == str2;
	int index = str1.find("es");
	std::cout << index << std::endl;
	CustomString* ret = str2.split(",");
	std::cout << ret << std::endl;
	return 0;
}