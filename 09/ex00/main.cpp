#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Need a file as argument." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange::storingdata("data.csv");
		BitcoinExchange::Bitcoin_exchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}