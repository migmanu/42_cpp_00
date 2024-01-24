#include "Phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	PhoneBook::contact_count = 0;
	std::cout << "PhoneBook class constructed default" << std::endl;
	return;
}

PhoneBook::PhoneBook(Contact new_contact)
{
	PhoneBook::contact_count = 0;
	PhoneBook::addContact(new_contact);
	std::cout << "PhoneBook class constructed parameterized" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook class destructed" << std::endl;
	return;
}

void	printOneContact(Contact contact_to_print)
{
	std::cout << "Name: " << contact_to_print.contact_name
		<< std::endl
		<< "Number: " << contact_to_print.contact_nbr
		<< std::endl;
}

void	PhoneBook::printContacts(void)
{
	for (int i = 0; i <= PhoneBook::contact_count; i++)
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

void	PhoneBook::addContact(Contact new_contact)
{
	if (PhoneBook::contact_count > 7)
	{
		std::cout << "Phonebook full. Replace "
			<< PhoneBook::contact_list[0].contact_name
			<< " whith " << new_contact.contact_name
			<< std::endl;
		PhoneBook::contact_list[0] = new_contact;
		return;
	}
	PhoneBook::contact_list[PhoneBook::contact_count] = new_contact;
	PhoneBook::contact_count++;
	std::cout << "Added " << new_contact.contact_name << " to phonebook" 
		<< std::endl;
	return;
}
