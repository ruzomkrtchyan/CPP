#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    // const Animal* j = new Dog(); 
    // const Animal* i = new Cat();
    // Animal **mix = new Animal*[100];

    // delete j;//should not create a leak delete i;
    // delete i;
    // for (size_t i = 0; i < 50; i++)
    //     mix[i] = new Cat();
    // for (size_t i = 50; i < 100; i++)
    //     mix[i] = new Dog();
    // for (size_t i = 0; i < 100; i++)
    // {
    //     mix[i]->makeSound();
    // }
    // for (size_t i = 0; i < 100; i++)
    // {
    //     delete mix[i];
    // }

    // delete []mix;

    Dog tmp;
    {
        Dog d = tmp;
    }
	return (0);
}