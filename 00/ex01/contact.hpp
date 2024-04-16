#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private :
	std :: string	_first_name;
	std :: string	_last_name;
	std :: string	_nickname;
	std :: string	_phonenum;
	std :: string	_secret;
	public :
		Contact ();
		void set_firstname(std :: string fname);
		void set_lastname(std :: string lname);
		void set_nickname(std :: string nname);
		void set_phone(std :: string phone);
		void set_secret(std :: string secret);
		std :: string get_firstname();
		std :: string get_lastname();
		std :: string get_nick();
		std :: string get_phone();
		std :: string get_secret();
};

#endif