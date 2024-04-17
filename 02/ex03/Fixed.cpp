#include "Fixed.hpp"

const int Fixed::fr_bits = 8;

Fixed::Fixed():fix_n(0)
{
}

Fixed::Fixed(const Fixed &other)
{
	this->fix_n = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
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
	fix_n = num * (1 << fr_bits);
}


Fixed::Fixed(const float num)
{
	fix_n = roundf(num * (1 << fr_bits));
}

Fixed:: ~Fixed()
{
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

bool Fixed:: operator>(const Fixed &num) const
{
	return (this->fix_n > num.fix_n);
}

bool Fixed:: operator<(const Fixed &num) const
{
	return (this->fix_n < num.fix_n);
}

bool Fixed:: operator>=(const Fixed &num) const
{
	return (this->fix_n >= num.fix_n);
}

bool Fixed:: operator<=(const Fixed &num) const
{
	return (this->fix_n <= num.fix_n);
}

bool Fixed:: operator==(const Fixed &num) const
{
	return (this->fix_n == num.fix_n);
}

bool Fixed:: operator!=(const Fixed &num) const
{
	return (this->fix_n != num.fix_n);
}

Fixed Fixed:: operator+(const Fixed &num)
{
	Fixed temp;
	temp.fix_n = fix_n + num.fix_n;
	return (temp);
}

Fixed Fixed:: operator-(const Fixed &num)
{
	Fixed temp;
	temp.fix_n = fix_n - num.fix_n;
	return (temp);
}

Fixed Fixed:: operator*(const Fixed &num)
{
	Fixed temp;
	temp.fix_n = toFloat() * num.toFloat();
	return (temp);
}

Fixed Fixed:: operator/(const Fixed &num)
{
	Fixed temp;
	temp.fix_n = fix_n / num.fix_n;
	return (temp);
}

Fixed Fixed:: operator++()
{
	this->fix_n++;
	return (*this);
}

Fixed Fixed:: operator++(int)
{
	Fixed temp(*this);
	this->fix_n++;
	return (temp);
}

Fixed Fixed:: operator--()
{
	this->fix_n--;
	return (*this);
}

Fixed Fixed:: operator--(int)
{
	Fixed temp(*this);
	this->fix_n--;
	return (temp);
}

const Fixed Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

Fixed Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}