#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	public:

		PhoneBook(void );
		PhoneBook(Contact new_contact);
		~PhoneBook(void);

		void printContacts(void);
		void printContacts(int i);

	private:

		Contact *contact_list;
		int		contact_count;
		void	printOneContact(Contact contact_to_print);
		void	addContact(Contact new_contact);
};

#endif
