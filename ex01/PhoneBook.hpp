#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#define MAX_CONTACTS 2

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void initPhoneBook(void);

  private:
	int commandRouter(std::string input);
	void addContactCommand(void);
	std::string getInput(std::string option);
	void addContact
		(
			std::string new_name,
			std::string new_last_name,
			std::string new_nickname,std::string new_phone_number,
			std::string new_secret
		);
	void printContacts(void);
	void printOneContact(Contact contact_to_print, int i);
	void printOneField(std::string field);
	std::vector<Contact> contact_list;
	int contact_count;
};

bool isAlphaString(std::string str);
bool isDigitString(std::string str);

#endif
