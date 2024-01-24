#include "main.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>

int	main(void)
{
	PhoneBook	new_phonebook("Maria", 234234);

	new_phonebook.addContact("Rax", 29);
	return (0);
}
