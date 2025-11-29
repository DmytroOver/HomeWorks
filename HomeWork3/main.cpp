// main.cpp : Defines the entry point for the application.
//

#include "main.h"


int main()
{
	SharedPtr p1{ new int(1) };
	std::cout << "*p1 " << *p1 << std::endl;
	{
		SharedPtr p2{ p1 };
		std::cout << "*p2 " << *p2 << std::endl;
		*p2 = 2;
		std::cout << "p2.useCount() " << p2.useCount() << std::endl;
	}
	std::cout << "*p1 " << *p1 << std::endl;
	std::cout << "p1.useCount() " << p1.useCount() << std::endl;
	SharedPtr p3;
	SharedPtr p4{ new int(4) };
	p3 = p4;
	std::cout << "p4.useCount() " << p4.useCount() << std::endl;
	p3.reset(new int(3));
	std::cout << "*p4 " << *p4 << std::endl;
	std::cout << "p4.isValid() " << p4.isValid() << std::endl;
	std::cout << "p4.useCount() " << p4.useCount() << std::endl;
	std::cout << "p3.isValid() " << p3.isValid() << std::endl;
	std::cout << "p3.useCount() " << p3.useCount() << std::endl;

	SharedPtr p5;
	std::cout << "p5.useCount() " << p5.useCount() << std::endl;
	{
		SharedPtr p6{ new int(6) };
		p5 = p6;
		std::cout << "p5.useCount() " << p5.useCount() << std::endl;
	}
	std::cout << "*p5 " << *p5 << std::endl;
	std::cout << "p5.useCount() " << p5.useCount() << std::endl;
	return 0;
}
