#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <limits>
#include <string>

PhoneBook::PhoneBook(void)
{
	PhoneBook::contact_count = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook class destructed" << std::endl;
	return;
}

void	PhoneBook::initPhoneBook(void)
{
	std::cout << std::endl;
	std::cout << "Welcome to The Phonebook" << std::endl;
	while (1)
	{
		std::cout
			<< "Possible commands are:"
			<< std::endl
			<< "1. ADD 2. SEARCH 3. EXIT"
			<< std::endl;
		std::cout << std::endl
				  << "Input a command ";
		std::string input;
		std::cin >> input;
		if (PhoneBook::commandRouter(input) == 1)
		{
			return;
		}
		system("clear");
		input.erase(input.begin(), input.end());
	}
}

int PhoneBook::commandRouter(std::string input)
{
	if (input[0] == '\0')
	{
		return (0);
	}
	else if (input.compare("EXIT") == 0 || input.compare("3") == 0)
	{
		std::cout << "Exiting now" << std::endl;
		return (1);
	}
	else if (input.compare("ADD") == 0 || input.compare("1") == 0)
	{
		system("clear");
		addContactCommand();
	}
	else if (input.compare("SEARCH") == 0 || input.compare("2") == 0)
	{
		system("clear");
		printContacts();
	}
	return (0);
}

void PhoneBook::addContactCommand(void)
{
	std::string input_name;
	std::string input_last_name;
	std::string input_nickname;
	std::string input_phone_number;
	std::string input_secret;

	std::cout << "Adding a new contact.\n1. Name" << std::endl;
	std::cin >> input_name;
	std::cout << "2. Last name:" << std::endl;
	std::cin >> input_last_name;
	std::cout << "3. Nickname:" << std::endl;
	std::cin >> input_nickname;
	std::cout << "4. Phone number:" << std::endl;
	std::cin >> input_phone_number;
	std::cout << "5. Darkest secret:" << std::endl;
	std::cin >> input_secret;

	Contact new_contact(
		input_name,
		input_last_name,
		input_nickname,
		input_phone_number,
		input_secret);

	if (PhoneBook::contact_count > 7)
	{
		PhoneBook::contact_list[0] = PhoneBook::contact_list[1];
		return;
	}
	PhoneBook::contact_list[PhoneBook::contact_count] = new_contact;
	PhoneBook::contact_count++;
	std::cout
		<< "Added "
		<< new_contact.getName()
		<< " to phonebook. Now have "
		<< PhoneBook::contact_count
		<< " contacts" << std::endl;
}

// If i smaller than 0 prints all info for one contact. Otherwise
// prints required by subject in 10 width
void PhoneBook::printOneContact(Contact contact_to_print, int i)
{
	if (i < 0)
	{
		std::cout << "Name: " << contact_to_print.getName() << std::endl
				  << "Last name: " << contact_to_print.getLastName() << std::endl
				  << "Nickname: "  << contact_to_print.getNickname() << std::endl
				  << "Phone number: " << contact_to_print.getPhoneNumber() << std::endl
				  << "Darkest secret: " << contact_to_print.getSecret() << std::endl;
		return;
	}
	std::cout
		<< std::setw(10)
		<< std::left
		<< i
		<< "|"
		<< std::setw(10)
		<< std::left
		<< contact_to_print.getName()
		<< "|" << std::setw(10)
		<< std::left
		<< contact_to_print.getLastName()
		<< "|"
		<< std::setw(10)
		<< std::left
		<< contact_to_print.getNickname()
		<< "|"
		<< std::endl;
}

void PhoneBook::printContacts(void)
{
	for (int i = 0; i < PhoneBook::contact_count; i++)
	{
		printOneContact(PhoneBook::contact_list[i], i);
	}

	int input;
	while (1)
	{
		std::cout << "Input contact's index for more info. "
				  << "Enter a negative number to go back" << std::endl;
		std::cin >> input;
		if (!std::cin.good())
		{
			std::cout << "Please input a number!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (input > contact_count - 1)
		{
			std::cout << "There are only " << contact_count << " contacts!" << std::endl;
			continue;
		}
		else if (input < 0)
		{
			return;
		}
		else
		{
			printOneContact(PhoneBook::contact_list[input], -1);
			return;
		}
	}
	return;
}

