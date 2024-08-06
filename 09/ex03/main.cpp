#include "PmergeMe.hpp"
#include <cstring>

void valid_input(int argc, char **argv)
{
	for (size_t i = 0; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
		{
			if (!std::isdigit(argv[i][j]))
				throw std::runtime_error("Error: Need a positive integer!");
		}
		if (std::strtod(argv[i], NULL) > 2147483647)
			throw std::overflow_error("Error: Value exceeds int max value.");
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Need a positive integer sequence." << std::endl;
		return 1;
	}
	try
	{
		valid_input(argc, argv + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}