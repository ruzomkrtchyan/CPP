#include "phonebook.hpp"

PhoneBook :: PhoneBook ()
{
	index = 0;
}

void	PhoneBook :: add(int i)
{
	std::string	user_com;
	
	if (index != 8)
		index = i + 1;
	std :: cout << "First Name 👉: ";
	std :: getline(std::cin, user_com);
	if (std::cin.eof())
		exit(1);
	contacts[i].set_firstname(user_com);
	std :: cout << "Last Name 👉: ";
	std :: getline(std::cin, user_com);
	if (std::cin.eof())
		exit(1);
	contacts[i].set_lastname(user_com);
	std :: cout << "Nickname 🤪: ";
	std :: getline(std :: cin, user_com);
	if (std::cin.eof())
		exit(1);
	contacts[i].set_nickname(user_com);
	std :: cout << "Phone number 📞: ";
	std :: getline(std :: cin, user_com);
	if (std::cin.eof())
		exit(1);
	contacts[i].set_phone(user_com);
	std :: cout << "Darkest secret 🤫: ";
	std :: getline(std :: cin, user_com);
	if (std::cin.eof())
		exit(1);
	contacts[i].set_secret(user_com);
}

std :: string	shorten(std :: string name)
{
	std :: string	yey = name;
	
	if (name.length() > 10)
		return(yey.substr(0, 9) + ".");
	return (yey);
}

void	PhoneBook :: search()
{
	int	i = 0;
	std :: string yey;
	int	num;

	if (index == 0)
	{
		std :: cout << "There is no contact, please ADD." << std :: endl;
		return ;
	}
	std :: cout << " ___________________________________________ " << std :: endl;
	std :: cout << "|   Index  |   Name   |  Surname | Nickname |"<< std :: endl;
	std :: cout << " ___________________________________________ " << std :: endl;
	while (i < index)
	{
		std :: cout << "|" << std :: setw(10) << i + 1 << "|";
		std :: cout << std :: setw(10) << shorten(contacts[i].get_firstname()) << "|";
		std :: cout << std :: setw(10) << shorten(contacts[i].get_lastname()) << "|";
		std :: cout << std :: setw(10) << shorten(contacts[i].get_nick()) << "|" << std :: endl;
		std :: cout << " ___________________________________________ " << std :: endl;
		i++;
	}
	std :: cout << "For more info please enter the index\n";
	while (!std::cin.eof())
	{
		std :: getline (std :: cin, yey);
		num =  std :: atoi(yey.c_str());
		if (num > index || num <= 0)
			std :: cout << "Wrong index" << std::endl;
		else
		{
			std :: cout << "First Name 👉: " << contacts[num - 1].get_firstname() << std :: endl;
			std :: cout << "Last Name 👉: " << contacts[num - 1].get_lastname() << std :: endl;
			std :: cout << "Nickame 🤪: " << contacts[num - 1].get_nick() << std :: endl;
			std :: cout << "Phone number 📞: " << contacts[num - 1].get_phone() << std :: endl;
			std :: cout << "Darkest secret 🤫: " << contacts[num - 1].get_secret() << std :: endl;
			break;
		}
	}
}
