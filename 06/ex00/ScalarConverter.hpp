#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cerrno>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void	intconvert(const std::string &dig);
	static void	charconvert(const std::string &str);
	static void	dlconvert(const std::string &str);
	static void	flconvert(const std::string &str);
	static void	ps_lit_convert(const std::string &str);
	static bool	all_dig(const std::string &str);
	static bool	is_dl(const std::string &str);
	static bool	is_fl(const std::string &str);
	static bool	is_ps_lit(const std::string &str);

public:
	static void	convert(const std::string &str);

	class ScalarConverter_exp : public std::exception
	{
		public:
			const char *what() const throw();
	};
};


#endif