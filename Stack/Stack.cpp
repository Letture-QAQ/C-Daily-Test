#include "Stack.h"

using namespace std;

void test2()
{
	Test t1;

	Stack stack;  // 实现此类，就俩模板函数，push和pop
	stack.push(111);
	stack.push<std::string>("asdfasdfasdf");

	Test t2;
	t2.p3 = "t2teststring";
	stack.push(t2);
	stack.push(&t1);

	t1.testWithStack(stack);

	int ret = 0;
	stack.pop(ret);
	std::cout << "testWithStack ret " << ret << std::endl;
}

int main() {
	test2();
	Test* test = new Test();

	Stack* stack = new Stack();
	test.testWithStack(stack);
	return 0;
}