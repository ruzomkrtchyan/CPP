#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *slot[4];
    public:
        Character();
        Character(std::string name);
        Charcter(const Character& other);
        Character& operator=(const Character& other);
        ~Character();
        std::string const & getName();
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};


#endif