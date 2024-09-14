#include "ScalarConverter.hpp"

bool ScalarConverter::all_dig(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::is_dl(const std::string &str)
{
	int dot = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.' && dot != 1)
				dot = 1;
			else
				return false;
		}
	}
	return true;
}

bool ScalarConverter::is_fl(const std::string &str)
{
	int fl = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.' && fl != 1)
				fl = 1;
			else if (str[i] == 'f' && fl == 1 && (i + 1 == str.size()))
				return true;
			else
				return false;
		}
	}
	return true;
}

bool ScalarConverter::is_ps_lit(const std::string &str)
{
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf"
		|| str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
		return true;
	return false;
}