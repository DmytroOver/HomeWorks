// HomeWork1.cpp : Defines the entry point for the application.
//

#include "HomeWork1.h"

using namespace std;

void connect(int)
{
	cout << "connect(int)" << endl;
}

void connect(int*)
{
	cout << "connect(int*)" << endl;
}

template <class T>
T clone(T t)
{
	return t;
}

class RAII
{
	int* data;
public:
	RAII& operator=(const RAII& other)
	{
		cout << "hi";
		return RAII();
	}

	int* operator->() const { return data; }
};

int main()
{
	int* p = nullptr;
	connect(p);

	p = 0;
	connect(p);

	RAII ob1;
	RAII ob2;
	ob2 = ob1;

	cout << "Hello World." << endl;
	return 0;
}
