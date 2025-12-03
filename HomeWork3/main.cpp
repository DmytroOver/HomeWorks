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

	SharedPtr p5( nullptr );
	std::cout << "p5.useCount() " << p5.useCount() << std::endl;
	{
		SharedPtr p6{ new int(6) };
		p5 = p6;
		std::cout << "p5.useCount() " << p5.useCount() << std::endl;
	}
	std::cout << "*p5 " << *p5 << std::endl;
	std::cout << "p5.useCount() " << p5.useCount() << std::endl;

	WeakPtr wp7;
	{
		SharedPtr p7(new int(7));
		wp7 = p7;
		std::cout << "wp7.lock().isValid() " << std::boolalpha << wp7.lock().isValid() << std::endl;
		WeakPtr wp8{ p7 };
		WeakPtr wp9(wp8);
		std::cout << "p7.useCount() " << p7.useCount() << std::endl;
		std::cout << "*wp9.lock() " << *(wp9.lock()) << std::endl;
	}
	std::cout << "wp7.expired() " << wp7.expired() << std::endl;

	return 0;
}
