#include "ABC.hpp"

Base::~Base(){};

Base* generate(void)
{
	std::srand(time(0));
	switch (std::rand() % 3 + 1)
	{
		case 1:
			return (new(A));
		case 2:
			return (new(B));
		case 3:
			return (new(C));
	}
	return NULL;
}

void identify(Base* p)
{
	A* aobj = dynamic_cast<A*>(p);
	B* bobj = dynamic_cast<B*>(p);
	C* cobj = dynamic_cast<C*>(p);

	if (aobj)
		std::cout << "The actual type of the object pointed to is A." << std::endl;
	else if (bobj)
		std::cout << "The actual type of the object pointed to is B." << std::endl;
	else if (cobj)
		std::cout << "The actual type of the object pointed to is C." << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	aobj = dynamic_cast<A&>(p);
		std::cout << "The actual type of the object pointed to is A." << std::endl;
	}
	catch(...)
	{}
	try
	{
		B	bobj = dynamic_cast<B&>(p);
		std::cout << "The actual type of the object pointed to is B." << std::endl;
	}
	catch(...)
	{}
	try
	{
		C	cobj = dynamic_cast<C&>(p);
		std::cout << "The actual type of the object pointed to is C." << std::endl;
	}
	catch(...)
	{}
}