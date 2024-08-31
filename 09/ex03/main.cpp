#include "PmergeMe.hpp"
#include <cstring>

void PmergeMe::valid_input(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
		{
			if (!std::isdigit(argv[i][j]))
				throw std::runtime_error("Error: Need a positive integer!");
		}
		if (std::strtod(argv[i], NULL) > 2147483647)
			throw std::overflow_error("Error: Value exceeds int max value.");
		vect.push_back(atoi(argv[i]));
		deq.push_back(atoi(argv[i]));
	}
}

void PmergeMe::timer()
{
	timeval start, end;
	gettimeofday(&start, NULL);
	ford_john(vect);
	gettimeofday(&end, NULL);
	double sec = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	std::cout << "After: " ;
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vect.size() <<" elements with std::vector : " << sec << " microseconds." << std::endl;
	
	gettimeofday(&start, NULL);
	ford_john(deq);
	gettimeofday(&end, NULL);
	double m_sec = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << deq.size() <<" elements with std::deque : ";
	std::cout << m_sec << " microseconds." << std::endl;

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
		PmergeMe obj;
		obj.valid_input(argc - 1, argv + 1);
		std::cout << "Before: ";
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
		obj.timer();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}