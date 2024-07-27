#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <stdexcept>
#include <ios>

class BitcoinExchange
{
private:
	static std::map<std::string, float> data_map;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange& operator=(const BitcoinExchange &other);
	~BitcoinExchange();

public:
	static void storingdata(std::string data);
	static bool is_valid_data(std::string data);
	static void Bitcoin_exchange(std::string input);
	static void Bitcoin_price(std::string data, float value);

	typedef std::map<std::string, float>::iterator map_it;

};



#endif