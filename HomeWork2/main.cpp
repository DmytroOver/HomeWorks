// main.cpp : Defines the entry point for the application.
//

#include "main.h"


int main()
{
	UniquePtr p1{ 1 };
	UniquePtr p2{ new int(2) };
	UniquePtr p3;
	std::cout << std::boolalpha;
	std::cout << "*p1 " << *p1 << std::endl;
	std::cout << "*p2 " << *p2 << std::endl;
	std::cout << "p3.isValid() " << p3.isValid() << std::endl;
	p3.reset(new int(3));
	std::cout << "p3 " << p3 << std::endl;
	std::cout << "*p3.release() " << *p3.release() << std::endl;
	std::cout << "p3.isVallid() " << p3.isValid() << std::endl;
	int* i4 = new int(4);
	{
		UniquePtr p4{ i4 };
		std::cout << "*p4.get() " << *p4.get() << std::endl;
		*p4 = 40;
		std::cout << "*p4 " << *p4 << std::endl;
	}
	std::cout << "*i4 " << *i4 << std::endl;
	std::cout << "p1.get() " << p1.get() << std::endl;
	p1.reset();
	std::cout << "p1.get() " << p1.get() << std::endl;

	UniquePtr p5{ std::move(p2) };
	std::cout << "*p5 " << *p5 << std::endl;
	std::cout << "p1.get() " << p2.get() << std::endl;
	UniquePtr p6{ new int(6) };
	UniquePtr p7 = std::move(p6);
	std::cout << "*p7 " << *p7 << std::endl;
	std::cout << "p6.isValid() " << p6.isValid() << std::endl;
	return 0;
}
