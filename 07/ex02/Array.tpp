#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array():_size(0), arr(NULL)
{}

template<typename T>
Array<T>::Array(unsigned int n):_size(n)
{
	arr = new T[_size];
	for (unsigned int i = 0; i < _size; ++i) 
		arr[i] = T();
}

template<typename T>
Array<T>::Array(const Array& other)
{
	arr = new T[other._size];
	for (unsigned int i = 0; i < other._size; ++i) 
		arr[i] = other[i];
}

template<typename T>
Array& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		if (arr)
			delete[] arr;
		arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i) 
			arr[i] = other[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	if (arr)
		delete[] arr;
}

template<typename T>
unsigned int Array<T>::size()
{
	return (_size);
}

template<typename T>
T& operator[](unsigned int ind) //const?
{
	if (ind < _size)
		return (arr[ind]);
	throw std::out_of_range("Index out of bounds");
}

#endif