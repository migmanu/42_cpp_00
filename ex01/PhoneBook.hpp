#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(std::string new_name, std::string new_last_name, std::string new_nickname,
					std::string new_phone_number, std::string new_secret);
	void printContacts(void);

  private:
	Contact contact_list[8];
	int contact_count;
	void printOneContact(Contact contact_to_print, int i);
};

#endif