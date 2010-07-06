/*!
 * \file	main.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 18:58:00
 *
 * more description...
 */

#include "SingletonHolder.h"
#include <iostream>

class Test
{
	public:
		Test() : _a(0), _b(0) {}
		void display()
		{
			std::cout << _a << " " << _b << std::endl;
		}

		void	setA(int a) { _a = a; }
		void	setB(int b) { _b = b; }

	private:
		int _a;
		int _b;
};

typedef	SingletonHolder<Test>		STest;

int main()
{
	Test	t;
	t.display(); // 0 0
	t.setA(1);
	t.setB(2);
	t.display(); // 1 2
	
	Test	t2;
	t2.display(); // 0 0

	Test*	st = STest::getInstance();
	st->setA(3);
	st->setB(4);
	st->display(); // 3 4

	Test*	st2 = STest::getInstance();
	st2->display(); // 3 4

	STest::destroy();

	Test*	st3 = STest::getInstance();
	st3->display(); // 0 0

	return (0);
}
