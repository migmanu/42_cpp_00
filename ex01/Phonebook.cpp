#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>
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

// If i smaller than 0 prints all info for one contact. Otherwise
// prints required by subject in 10 width
void	PhoneBook::printOneContact(Contact contact_to_print, int i)
{
	if (i < 0)
	{
		std::cout 
			<< contact_to_print.name << std::endl
			<< contact_to_print.last_name << std::endl
			<< contact_to_print.nickname << std::endl
			<< contact_to_print.phone_number << std::endl
			<< contact_to_print.secret << std::endl;
		return;

	}
	std::cout
		<< std::setw(10) << std::left << i
		<< std::setw(10) << std::left << contact_to_print.name
		<< std::setw(10) << std::left << contact_to_print.last_name
		<< std::setw(10) << std::left << contact_to_print.nickname
		<< std::endl;
}

void	PhoneBook::printContacts(void)
{
	for (int i = 0; i < PhoneBook::contact_count; i++)
	{
		printOneContact(PhoneBook::contact_list[i], i);
	}

	std::cout << "Input contact's index for more info." << std::endl;
	int input;
	std::cin >> input;

	if (input > contact_count)
	{
		std::cout
			<< "There are only "
			<< contact_count
			<< "contacts!"
			<< std::endl;
		return;
	}
	if (input < 0)
	{
		std::cout << "Index cannot be smaller than 0!" << std::endl;
		return;
	}
	printOneContact(PhoneBook::contact_list[input], -1);
	return;
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
