#include "contact.hpp"


Contact :: Contact ()
{
}
void Contact :: set_firstname(std :: string fname)
{
	_first_name = fname;
}
void Contact :: set_lastname(std :: string lname)
{
	_last_name = lname;
}
void Contact :: set_nickname(std :: string nname)
{
	_nickname = nname;
}
void Contact :: set_phone(std :: string phone)
{
	_phonenum = phone;
}
void Contact :: set_secret(std :: string secret)
{
	_secret = secret;
}
std :: string Contact :: get_firstname()
{
	return (_first_name);
}
std :: string Contact :: get_lastname()
{
	return (_last_name);
}
std :: string Contact :: get_nick()
{
	return (_nickname);
}
std :: string Contact :: get_phone()
{
	return (_phonenum);
}
std :: string Contact :: get_secret()
{
	return (_secret);
}