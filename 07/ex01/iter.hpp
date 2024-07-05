#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter(T* arr, size_t length, void (*f)(T&))
{
    for (size_t i, i < length, i++)
        f(arr[i]);
}

template <typename T> void iter(T* arr, size_t length, void (*f)(T const &))
{
    for (size_t i, i < length, i++)
        f(arr[i]);
}

#endif