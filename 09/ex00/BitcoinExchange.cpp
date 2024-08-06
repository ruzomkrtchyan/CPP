#include "BitcoinExchange.hpp"
std::map<std::string, float> BitcoinExchange::data_map;

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::storingdata(std::string data)
{
	std::ifstream file(data);

	if(!file.is_open())
		throw std::ios_base::failure("Failed to open the file.");
	std::string line;
	while(std::getline(file,line))
	{
		if(!line.compare("date,exchange_rate"))
			continue;
		std::size_t delim = line.find(",");
		if (delim == std::string::npos)
			throw std::runtime_error("Bad data format.");
		std::string key = line.substr(0, delim);
		double value = std::strtod(line.substr(delim + 1).c_str(), NULL);
		data_map.insert(std::pair<std::string, float>(key, value));
	}
	file.close();
}

bool BitcoinExchange::is_valid_data(std::string data)
{
	if (data.size() != 10)
		return false;
	if (data[4] != '-' ||  data[7] != '-')
		return false;
	for(size_t i = 0; i < data.size(); ++i)
	{
		if (i != 4 && i != 7)
		{
			if(!std::isdigit(data[i]))
				return false;
		}
	}

	int year = std::atoi(data.substr(0,4).c_str());
	int month = std::atoi(data.substr(5,2).c_str());
	int day = std::atoi(data.substr(8,2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;
	int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0)
		if (year % 100 != 0 || year % 400 == 0)
			month_days[1] = 29;
	if (day > month_days[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::is_valid_val(std::string value)
{
	if (value[0] != ' ')
		return false;
	int dot = 0;
	for(size_t i = 1; i < value.size(); ++i)
	{
		if (value[i] == '.')
		{
			dot++;
			i++;
		}
		if(!std::isdigit(value[i]) || dot > 1)
			return false;
	}
	return true;
}
void BitcoinExchange::Bitcoin_price(std::string data, float value)
{
	map_it it = data_map.lower_bound(data);
	if (it != data_map.end() && it->first == data)
		std::cout << data << " => " << value << " = " << value * it->second << std::endl;
	else
	{
		if (it != data_map.begin())
			--it;
		std::cout << data << " => " << value << " = " << value * it->second << std::endl;
	}
}

void BitcoinExchange::Bitcoin_exchange(std::string input)
{
	std::ifstream file(input);
	int fl = 0;

	if(!file.is_open())
		throw std::ios_base::failure("Failed to open the input file.");
	std::string line;
	while(std::getline(file,line))
	{
		if (!line.compare("date | value") && fl != 1)
		{
			fl = 1;
			continue;
		}
		std::size_t delim = line.find("|");
		std::string data = line.substr(0, delim - 1);
		if (delim == std::string::npos || !is_valid_data(data))
		{
			std::cerr << "Error: bad input => " << data <<std::endl;
			continue;
		}
		if (delim + 1 >= line.size() || !is_valid_val(line.substr(delim + 1)))
		{
			std::cerr << "Error: bad value => " << line.substr(delim + 1) <<std::endl;
			continue;
		}
		float value = std::strtod(line.substr(delim + 2).c_str(), NULL);
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		Bitcoin_price(data, value);
	}
}