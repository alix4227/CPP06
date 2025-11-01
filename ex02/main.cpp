#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
	srand(time(NULL));
	int i = rand()%3;
	int j = 0;
	Base* identify;
	Base* str[3] = {new A, new B, new C};
	while ( j < 3)
	{
		if (j == i)
		{
			identify = str[i];
			break ;
		}
		j++;
	}
	j = 0;
	while (j < 3)
	{
		if (j != i)
			delete str[j];
		j++;
	}
	return (identify);
}

void identify(Base* p)
{
	A*a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << "Object of type A" << std::endl;
	B*b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << "Object of type B" << std::endl;
	C*c = dynamic_cast<C*>(p);
	if (c != NULL)
		std::cout << "Object of type C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Object of type A" << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Object of type B" << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Object of type C" << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
	}
}

int main()
{
	Base* a = generate();
	identify(a);
	identify(*a);
	delete a ;
	return (0);
}