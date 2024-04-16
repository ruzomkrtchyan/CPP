#include "phonebook.hpp"

int main()
{
	PhoneBook	phonebook;
	std :: string	user_com;
	int	i = 0;

	while (!std::cin.eof()) 
	{
		std::getline(std::cin, user_com);
		if (user_com == "EXIT") 
			break;
		else if (user_com == "ADD")
		{
			if (i == 8)
				i = 0;
			phonebook.add(i);
			if (i == 7)
				std :: cout << "It's yours last contact✨\n";
			i++;
		}
		else if (user_com == "SEARCH")
			phonebook.search();
		else
			std :: cout << "Not correct command!!!!" << std :: endl;
	}
	std :: cout << "Goodbye my dear💘" << std :: endl;
}