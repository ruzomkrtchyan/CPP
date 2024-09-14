#include "iter.hpp"

int main()
{
    int arr[] = {12, 13, 14, 15, 16};
    const int arr1[] = {5, 2, 8, 3};

    iter(arr, 5, print);
    iter(arr1, 4, print);
}