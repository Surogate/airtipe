/*!
 * \file	main.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 23:49:32
 */

#include	"smartPtr.h"
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

int main()
{
	int 			toto = 5;
	SmartPtr<int>	sp(&toto);
	std::cout << *sp << std::endl;

	Test			c(10);
	SmartPtr<Test>	sp2(&c);
	sp2->display();

	SmartPtr<Test>	sp3 = sp2;

	return (0);
}
