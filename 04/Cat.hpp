#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public virtual Animal 
{
    protected:
        std::string type;
    public:
        Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        virtual ~Cat();

        void makesound();
        std::string getType();
}


#endif