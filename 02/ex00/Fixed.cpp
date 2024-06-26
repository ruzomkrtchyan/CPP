#include "Fixed.hpp"

const int Fixed::fr_bits = 8;

Fixed::Fixed():fix_n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fix_n = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->fix_n = rhs.getRawBits();
	return(*this);
}

Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fix_n);
}

void Fixed::setRawBits( int const raw )
{
	this->fix_n = raw;
}