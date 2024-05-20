#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual Animal 
{
    private:
        Brain *head;
    protected:
        std::string type;
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        ~Dog();

        void makeSound() const;
        std::string getType() const;
};


#endif