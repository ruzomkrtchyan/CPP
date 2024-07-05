#include "ABC.hpp"

int main()
{
    Base *p = generate();
    Base *a = new A;
    Base *b = new B;
    Base *c = new C;

    identify(p);
    identify(*a);
    identify(*b);
    identify(*c);

    delete p;
    delete a;
    delete b;
    delete c;
}