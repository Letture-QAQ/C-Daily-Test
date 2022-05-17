#include <iostream>

class StackInfo {
public:
	/*//1.第一种方法 尝试用shared_ptr来代替void*  --- 失败了 等我再想想
	template <typename T>
	std::shared_ptr<T> pInfo;
	std::shared_ptr<T> pInfo = std::make_shared<T>(T);
	StackInfo() {
		pInfo = nullptr;
	}

	StackInfo(T* data) {
		std::shared_ptr<T> pInfo((T*)data);
	}*/
	//2.用void* 但是没办法获得传参的类型用于释放内存
	void* data;
	StackInfo* pLast;

	StackInfo() {
		data = nullptr;
		pLast = nullptr;
	}
};

class Stack {
public:
	Stack() {
		pTop = nullptr;
	}

	Stack(Stack* stack) {
		while (stack->pTop != nullptr) {
			this->push(stack->pTop->data);
			stack->pTop = stack->pTop->pLast;
		}
	}

	template <typename T>
	void push(T inData) {
		if (pTop == nullptr) {
			pTop = new StackInfo();
			pTop->data = new T(inData);
			pTop->pLast = nullptr;
			return;
		}

		StackInfo* pTemp = new StackInfo();
		pTemp->data = new T(inData);
		pTemp->pLast = pTop;
		pTop = pTemp;
	}

	template <typename T>
	void pop(T& inData){
		if (pTop == nullptr) {
			return;
		}
		StackInfo* pTemp = pTop;
		while (pTemp != nullptr) {
			if (pTemp->data != inData) {
				pTemp = pTemp->pLast;
			}
			else {
				pTemp->pLast = pTemp->pLast->pLast;
				pTop = pTemp;
				break;
			}
		}
	}
public:
	StackInfo* pTop;
};

class Test
{
public:
	int p1 = 1;
	bool p2 = false;
	std::string p3 = "p33333333";

	void testWithStack(Stack& stack)
	{
		int v1 = 0;
		std::string v2;
		Test v3;
		Test* v4 = nullptr;

		stack.pop<Test*>(v4);
		stack.pop(v3);
		stack.pop(v2);
		stack.pop(v1);

		std::cout << "testWithStack "
			<< v1 << " "
			<< v2 << " "
			<< v3.p3 << " "
			<< v4->p3 << std::endl;

		stack.push(1);
	}
};