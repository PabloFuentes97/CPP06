#include "funcs.hpp"

Base * generate(void)
{
	srand((unsigned) time(NULL)); 
	int	n = rand() % 3;

	std::cout << "Random number: " << n << std::endl;
	switch(n)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	//A
	if (dynamic_cast<A *>(p))
	{
		std::cout << "It's an A object" << std::endl;
		return ;
	}

	//B
	if (dynamic_cast<B *>(p))
	{
		std::cout << "It's a B object" << std::endl;
		return ;
	}

	//C
	if (dynamic_cast<C *>(p))
	{
		std::cout << "It's a C object" << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	//A
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "It's an A object" << std::endl;
		return ;
	}
	catch(const std::bad_cast& bc)
	{
		std::cerr << bc.what() << " A type" << '\n';
	}

	//B
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "It's a B object" << std::endl;
		return ;
	}
	catch(const std::bad_cast& bc)
	{
		std::cerr << bc.what() << " B type" << '\n';
	}

	//C
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "It's a C object" << std::endl;
		return ;
	}
	catch(const std::bad_cast& bc)
	{
		std::cerr << bc.what() << " C type" << '\n';
	}
}