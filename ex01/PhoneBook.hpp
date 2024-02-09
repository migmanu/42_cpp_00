#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void initPhoneBook(void);

  private:
	int commandRouter(std::string input);
	void addContactCommand(void);
	void addContact
		(
			std::string new_name,
			std::string new_last_name,
			std::string new_nickname,std::string new_phone_number,
			std::string new_secret
		);
	void printContacts(void);
	void printOneContact(Contact contact_to_print, int i);
	Contact contact_list[8];
	int contact_count;
};

#endif
