#include "Harl.hpp"

int main (int argc, char **argv)
{
	Harl mard;
	if (argc < 2)
	{
		std::cout << "Need complain level." << std::endl;
		return(1);
	}
	mard.complain(argv[1]);
	
}