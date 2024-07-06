#include "iter.hpp"

class Awesome
{
private:
    int _n;
public:
    Awesome():_n(42){return;}
    int get(void)const{return _n;}
};

std::ostream &operator<<(std::ostream & o, Awesome const &rhs)
{
    o<<rhs.get();
    return o;
}

// template <typename T>
// void print(T const & x){std::cout<< x << std::endl;}

int main()
{
    int arr[] = {12, 13, 14, 15, 16};
    // Awesome tab[5];

    iter(arr, 5, print);
    // iter(tab, 5, print);
}