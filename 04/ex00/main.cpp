#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main() 
// {
//     const Animal* meta = new Animal(); 
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     const WrongAnimal* fake = new WrongCat();

//     // std::cout << j->getType() << " " << std::endl; 
//     // std::cout << i->getType() << " " << std::endl; 
//     // i->makeSound(); //will output the cat sound! 
//     // j->makeSound();
//     meta->makeSound();
//     fake->makeSound();

//     delete meta;
//     delete j;
//     delete i;
//     delete fake;

//     return 0;  
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "SOUND: \n";
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    // Test WrongCat
    std::cout << wrong->getType() << " " << std::endl;
    wrong->makeSound();

    // Clean up
    delete meta;
    delete j;
    delete i;
    delete wrong;

    return 0;
}