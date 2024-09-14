#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Need a positive integer sequence." << std::endl;
		return 1;
	}
	try 
	{
		PmergeMe obj;
		obj.valid_input(argc - 1, argv + 1);
		std::cout << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << atoi(argv[i]) << " ";
		std::cout << std::endl;
		obj.timer();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}