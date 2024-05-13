#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public virtual Animal 
{
    protected:
        std::string type;
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        virtual ~Dog();

        void makesound();
        std::string getType();
}


#endif