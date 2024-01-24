#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:

		PhoneBook(void );
		PhoneBook(std::string name, int nbr);
		~PhoneBook(void);

		void	addContact(std::string name, int nbr);
		void	printContacts(void);
		void	printContacts(int i);

	private:

		Contact contact_list[8];
		int		contact_count;
		void	printOneContact(Contact contact_to_print);
};

#endif
