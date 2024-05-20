#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fix_n;
		static const int fr_bits;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &rhs);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
		bool operator>(const Fixed &num) const;
		bool operator<(const Fixed &num) const;
		bool operator>=(const Fixed &num) const;
		bool operator<=(const Fixed &num) const;
		bool operator==(const Fixed &num) const;
		bool operator!=(const Fixed &num) const;
		
		Fixed operator+(const Fixed &num);
		Fixed operator-(const Fixed &num);
		Fixed operator/(const Fixed &num);
		Fixed operator*(const Fixed &num);
		
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		static const Fixed& max(const Fixed &num1,const Fixed &num2);
		static const Fixed& min(const Fixed &num1,const Fixed &num2);
		static Fixed& max(Fixed &num1, Fixed &num2);
		static Fixed& min(Fixed &num1, Fixed &num2);



};

std::ostream& operator<<(std::ostream &os, const Fixed &num);

#endif