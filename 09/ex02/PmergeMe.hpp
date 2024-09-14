#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> vect;
	std::deque<int> deq;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	void valid_input(int argc, char **argv);
	void timer();
	template <typename T> void insert_n(T &cont, T s_nums);
	template <typename T> void ford_john(T &cont);
};

template <typename T>
void PmergeMe::insert_n(T &cont, T s_nums)
{
	if (s_nums.size() < 2)
	{
		cont.insert(std::upper_bound(cont.begin(), cont.end(), *s_nums.begin()), *s_nums.begin());
		return ;
	}
	size_t pow_2 = 2;
	for (size_t i = 0; i < s_nums.size(); i++)
	{
		typename T::iterator it;
		size_t n = std::min(pow_2, s_nums.size());
		it = s_nums.begin() + n;
		while (it != s_nums.begin())
		{
			--it;
			cont.insert(std::upper_bound(cont.begin(), cont.end(), *it), *it);
		}
		s_nums.erase(s_nums.begin(), s_nums.begin() + n);
		pow_2 = pow(pow_2, i + 2) - pow_2;
	}
}

template <typename T>
void PmergeMe::ford_john(T &cont)
{
	T l_nums;
	T s_nums;

	if(cont.size() > 3)
	{
		for (size_t i = 0; i < cont.size(); i += 2)
		{
			if (i == cont.size() - 1)
			{
				s_nums.push_back(cont[i]);
				break ;
			}
			if (cont[i] > cont[i + 1])
				std::swap(cont[i], cont[i + 1]);
			s_nums.push_back(cont[i]);
			l_nums.push_back(cont[i + 1]);
		}
		cont = l_nums;
		size_t first_s = 0;
		for (size_t i = 1; i < cont.size(); ++i)
			if (cont[first_s] > cont[i])
				first_s = i;
		ford_john(cont);
		cont.insert(cont.begin(), s_nums[first_s]);
		s_nums.erase(s_nums.begin() + first_s);
		insert_n(cont, s_nums);
	}
	else if (cont.size() > 1)
	{
		if(cont[0] > cont[1])
			std::swap(cont[0], cont[1]);
		if(cont.size() == 3)
		{
			s_nums.push_back(cont[2]);
			cont.erase(cont.end() - 1);
			insert_n(cont, s_nums);
		}
	}
	
}

#endif