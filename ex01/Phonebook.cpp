#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string>

PhoneBook::PhoneBook(void)
{
	PhoneBook::contact_count = 0;
	std::cout << "PhoneBook class constructed default" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook class destructed" << std::endl;
	return;
}

void	PhoneBook::printOneContact(Contact contact_to_print)
{
	std::cout << "Name: " << contact_to_print.name
		<< std::endl
		<< "Number: " << contact_to_print.phone_number
		<< std::endl;
}

void	PhoneBook::printContacts(void)
{
	for (int i = 0; i < PhoneBook::contact_count; i++)
	{
		printOneContact(PhoneBook::contact_list[i]);
	}
	return;
}

void	PhoneBook::printContacts(int i)
{
	if (i < 1 || i > 8)
	{
		std::cout << "Contacts in phonebook range from 1 to 8" << std::endl;
		return;
	}
	printOneContact(PhoneBook::contact_list[i - 1]);
}

void	PhoneBook::addContact(std::string new_name, std::string new_last_name,
		   std::string new_nickname, std::string new_phone_number,
		   std::string new_secret)
{
	Contact new_contact(new_name, new_last_name, new_nickname,
		new_phone_number, new_secret);

	if (PhoneBook::contact_count > 7)
	{
		PhoneBook::contact_list[0] = PhoneBook::contact_list[1];
		return;
	}
	PhoneBook::contact_list[PhoneBook::contact_count] = new_contact;
	PhoneBook::contact_count++;
	std::cout << "Added " << new_contact.name << " to phonebook. Now have "
		<< PhoneBook::contact_count << " contacts"
		<< std::endl;
	return;
}
