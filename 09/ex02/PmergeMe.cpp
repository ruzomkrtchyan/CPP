#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		deq = other.deq;
		vect = other.vect;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

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
