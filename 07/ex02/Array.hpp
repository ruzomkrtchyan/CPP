#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array
{
	private:
		T* arr;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array<T>& operator=(const Array<T>& other);
		~Array();

		unsigned int size() const;
		T& operator[](unsigned int ind);
		const T& operator[](unsigned int ind) const;
};

#include "Array.tpp"

#endif