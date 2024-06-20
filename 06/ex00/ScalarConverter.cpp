#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

bool    ScalarConverter::checker(std::string param)
{
    if ()
    {
        /* code */
    }
    
}

void	ScalarConverter::intconvert(std::string dig)
{
	int	num;

	num = stoi(dig);
	std::cout << "char: " << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) <<std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void ScalarConverter::convert(std::string str)
{
   if (std::all_of(str.begin(), str.end(), ::isdigit))
		intconvert(str);
}

char
int
float
double