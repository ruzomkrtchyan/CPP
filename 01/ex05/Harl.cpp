#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my" 
		<< " 7XL-double-cheese-triple-pickle-specialketchup burger." 
		<< "I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." 
		<< "You didn't put enough bacon in my burger!"
		<< "If you did, I wouldn't be asking for more!"<< std::endl;

}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." 
		<< "I've been coming for years whereas you started "
		<< "working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain( std::string level )
{
	int	i = 0;
	std::string funct[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (level != funct[i] && i < 4)
		i++;
	switch(i)
	{
		case(4):
			std::cout << "There is no complain" << std::endl;
			exit(1);
	}
	(this->*fptr[i])();
}