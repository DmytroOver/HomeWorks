// main.cpp : Defines the entry point for the application.
//

#include "main.h"


int main()
{
	UniquePtr p1{ 1 };
	UniquePtr p2{ new int(2) };
	UniquePtr p3;
	std::cout << std::boolalpha;
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	std::cout << p3.isValid() << std::endl;
	p3.reset(new int(3));
	std::cout << p3 << std::endl;
	std::cout << *p3.release() << std::endl;
	std::cout << p3.isValid() << std::endl;
	int* i4 = new int(4);
	{
		UniquePtr p4{ i4 };
		std::cout << *p4.get() << std::endl;
		*p4 = 40;
		std::cout << *p4 << std::endl;
	}
	std::cout << *i4 << std::endl;
	std::cout << p1.get() << std::endl;
	p1.reset();
	std::cout << p1.get() << std::endl;
	return 0;
}
