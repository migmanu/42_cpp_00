#include "main.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>

void	add_contact(PhoneBook *phonebook)
{
	std::string	input_name;
	std::string	input_last_name;
	std::string	input_nickname;
	std::string	input_phone_number;
	std::string	input_secret;

	std::cout << "Adding a new contact.\nName" << std::endl;
	std::cin >> input_name;
	std::cout << "Last name:" << std::endl;
	std::cin >> input_last_name;
	std::cout << "Nickname:" << std::endl;
	std::cin >> input_nickname;
	std::cout << "Phone number:" << std::endl;
	std::cin >> input_phone_number;
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> input_secret;

	phonebook->addContact(input_name, input_last_name, input_nickname,
		input_phone_number, input_secret);
}

int	command_router(PhoneBook *phonebook, std::string input)
{
	if (input.compare("EXIT") == 0)
	{
		std::cout << "Exiting now" << std::endl;
		return (1);
	}
	else if (input.compare("ADD") == 0)
	{
		add_contact(phonebook);
	}
	else if (input.compare("SEARCH") == 0)
	{
		*(phonebook)::
	}
	else
	{
		std::cout << "Acceptable commands are 'ADD', 'SEARCH' and 'EXIT'"
			<< std::endl;
	}
	return (0);
}

int	main(void)
{
	PhoneBook	phonebook;

	std::cout << std::endl;
	std::cout << "Welcome to The Phonebook" << std::endl;
	std::cout << "Input a command" << std::endl;
	while (1)
	{
		std::string	input;
		std::cin >> input;
		if (command_router(&phonebook, input) == 1)
		{
			return (0);
		}
	}
	return (0);
}
