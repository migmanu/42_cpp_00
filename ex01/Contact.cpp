#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::Contact(std::string new_name, std::string new_last_name, std::string new_nickname,
				 std::string new_phone_number, std::string new_secret)
{
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

std::string Contact::getName(void)
{
	return this->name;
}

std::string Contact::getLastName(void)
{
	return this->last_name;
}

std::string Contact::getNickname(void)
{
	return this->nickname;
}

std::string Contact::getPhoneNumber(void)
{
	return this->phone_number;
}

std::string Contact::getSecret(void)
{
	return this->secret;
}
