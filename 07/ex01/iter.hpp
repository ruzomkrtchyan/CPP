#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void print(T &value)
{
	std::cout << value << std::endl;
}

template <typename T> void iter(T* arr, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T, typename U> void iter(T* arr, size_t length, void (*f)(U &))
{
	for (size_t i  = 0; i < length; i++)
		f(arr[i]);
}

#endif