#include "main.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>

int	main(void)
{
	Contact new_contact("Maria", 234);
	PhoneBook	phonebook(new_contact);
	return (0);
}
