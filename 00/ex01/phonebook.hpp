#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>


class PhoneBook
{
	private :
	Contact	contacts[8];
	int		index ;

	public :
	PhoneBook ();
	void add(int i);
	void search();
};

std :: string	shorten(std :: string name);

#endif