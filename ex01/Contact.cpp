#include "main.hpp"

Contact::Contact ( void )
{
	std::cout << "Contact class constructed default" << std::endl;
	return;
}

Contact::Contact ( std::string name, int nbr )
{
	std::cout << "Contact class constructed parameterized" << std::endl;
	contact_name = name;
	contact_nbr = nbr;
	return;
}

Contact::~Contact ( void )
{
	std::cout << "Contact class destructed" << std::endl;
	return;
}
