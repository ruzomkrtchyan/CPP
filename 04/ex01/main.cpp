#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main() 
// {
//     const Animal* j = new Dog(); 
//     const Animal* i = new Cat();
//     Animal **mix = new Animal*[100];

//     delete j;//should not create a leak delete i;
//     delete i;
//     for (size_t i = 0; i < 50; i++)
//         mix[i] = new Cat();
//     for (size_t i = 50; i < 100; i++)
//         mix[i] = new Dog();
//     for (size_t i = 0; i < 100; i++)
//     {
//         mix[i]->makeSound();
//     }
//     for (size_t i = 0; i < 100; i++)
//     {
//         delete mix[i];
//     }

//     delete []mix;
    
// 	return (0);
// }

int main() {
    std::cout << "Creating and filling array of Animal objects..." << std::endl;
    Animal* animals[4];

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "Deleting every Animal..." << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "Creating and deleting Dog and Cat objects..." << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "All tests completed." << std::endl;
    return 0;
}