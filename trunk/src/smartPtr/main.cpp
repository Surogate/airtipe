/*!
 * \file	main.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 23:49:32
 */

#include	"SmartPointer.h"
#include	"Counter.h"
#include	<iostream>

class	Test
{
	public:
		Test() : _a(0) {}
		Test(int a) : _a(a) {}

	public:
		void	setA(int a) { _a = a; }
		void	display() { std::cout << _a << std::endl; }

	private:
		int		_a;
};

int		main()
{
	SmartPointer<int>	sp(new int(5));
	std::cout << *sp << std::endl;
	*sp = 7;
	std::cout << *sp << std::endl;

	SmartPointer<Test>	sp3;

	{
		SmartPointer<Test>	sp2(new Test(10));
		sp2->display();
		sp3 = sp2;
	} // destroying sp2 here, but keeped reference for sp3

	sp3->display();
	sp3->setA(2);

	SmartPointer<Test>	sp4(sp3);
	sp4->display();

	return (0);
}
