#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Need an expression as argument." << std::endl;
		return 1;
	}
	RPN obj;
	if(!obj.valid_exp(argv[1]))
	{
		std::cerr << "Not a valid expression." << std::endl;
		return 1;
	}
	try
	{
		std::cout << obj.compute(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
