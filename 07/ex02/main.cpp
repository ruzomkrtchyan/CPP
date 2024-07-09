#include "Array.hpp"

int main()
{
    Array<int> arr(5);
    try
    {
        std::cout << arr[1] << std::endl;
        std::cout << arr.size() << std::endl;
        std::cout << arr[6] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}