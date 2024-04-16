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

std::ostream& operator<<(std::ostream &os, const Fixed &num)
{
	os << num.toFloat();
	return (os);
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	fix_n = num * (1 << fr_bits);
}


Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	fix_n = roundf(num * (1 << fr_bits));
}

Fixed:: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->fix_n);
}

void Fixed::setRawBits( int const raw )
{
	this->fix_n = raw;
}

float Fixed::toFloat( void ) const
{
	float num = static_cast<float>(this->fix_n);
	return (num / (1 << fr_bits));
}

int Fixed::toInt( void ) const
{
	int num = static_cast<int>(fix_n);
	return (num / (1 << fr_bits));
}