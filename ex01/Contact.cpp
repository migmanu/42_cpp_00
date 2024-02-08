#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact class contructed" << std::endl;
	return;
}

Contact::Contact(std::string new_name, std::string new_last_name, std::string new_nickname,
				 std::string new_phone_number, std::string new_secret)
{
	std::cout << "Contact class constructed parameterized" << std::endl;
	name = new_name;
	last_name = new_last_name;
	nickname = new_nickname;
	phone_number = new_phone_number;
	secret = new_secret;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact class destructed" << std::endl;
	return;
}
