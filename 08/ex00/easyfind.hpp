#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <iterator>

template <typename T>
void easyfind(T &container, int occurence)
{
	typename T::iterator it = std::find(container.begin(), container.end(), occurence);

	if (it == container.end())
		throw std::out_of_range("No occurrence is found in the container.");
	std::cout << "The firs occurence was found at index " << std::distance(container.begin(), it) << "." << std::endl;
}

#endif