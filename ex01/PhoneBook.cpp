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
		std::getline(std::cin, input);
		if (PhoneBook::commandRouter(input) == 1)
		{
			return;
		}
		std::cout << std::endl << "Press any key to continue..." << std::endl;
		std::cin.ignore().get();
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

// gets input from user until input is valid. Flag 'alpha' for only
// alpha characters, flag 'digit' for only digits
std::string PhoneBook::getInput(std::string option)
{
	std::string input;
	if (option.compare("alpha") == 0)
	{
		while (1)
		{
			std::cout << ">> ";
			std::getline(std::cin, input);
			if (isAlphaString(input))
			{
				return (input);
			}
			std::cout << "Only alpha characters allowed" << std::endl;
		}
	}
	else if (option.compare("digit") == 0)
	{
		while (1)
		{
			std::cout << ">> ";
			std::getline(std::cin, input);
			if (isDigitString(input))
			{
				return (input);
			}
			std::cout << "Only numbers allowed" << std::endl;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (input);
}

void PhoneBook::addContactCommand(void)
{
	std::string input_name;
	std::string input_last_name;
	std::string input_nickname;
	std::string input_phone_number;
	std::string input_secret;

	std::cout << "Adding a new contact." << std::endl
		<< "1. Name" << std::endl;
	input_name = getInput("alpha");
	std::cout << "2. Last name:" << std::endl;
	input_last_name = getInput("alpha");
	std::cout << "3. Nickname:" << std::endl;
	input_nickname = getInput("alpha");
	std::cout << "4. Phone number:" << std::endl;
	input_phone_number = getInput("digit");
	std::cout << "5. Darkest secret:" << std::endl;
	input_secret = getInput("alpha");

	Contact new_contact(
		input_name,
		input_last_name,
		input_nickname,
		input_phone_number,
		input_secret);

	if (PhoneBook::contact_count >= MAX_CONTACTS)
	{
		contact_list.erase(contact_list.begin());
		contact_list.push_back(new_contact);
	}
	else
	{
		contact_list.push_back(new_contact);
		PhoneBook::contact_count++;
	}
	std::cout
		<< "Added "
		<< new_contact.getName()
		<< " to phonebook. Now have "
		<< PhoneBook::contact_count
		<< " contacts" << std::endl;
}

void PhoneBook::printOneField(std::string field)
{
	std::string toPrint = field;
	if (field.length() > 10)
	{
		toPrint.resize(9);
		toPrint.append(".");
	}
	std::cout << "|" << std::setw(10) << std::right << toPrint;
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
	std::cout << "|" << std::setw(10) << std::right << i;
	printOneField(contact_to_print.getName());
	printOneField(contact_to_print.getLastName());
	printOneField(contact_to_print.getNickname());
	std::cout << std::endl;
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

