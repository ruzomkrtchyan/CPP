#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
        ~Brain();

        void setIdeas(int i, std::string &newid);
        std::string getIdeas(int i);
};



#endif