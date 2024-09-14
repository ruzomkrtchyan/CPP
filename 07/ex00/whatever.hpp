#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T> T min(T &n1, T &n2)
{
	return (n1 < n2) ? n1 : n2;
}

template <typename T> T max(T &n1, T &n2)
{
	return (n1 > n2) ? n1 : n2;
}

#endif