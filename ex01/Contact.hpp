#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <ostream>
#include <string>

class Contact
{
  public:
	Contact(void);
	Contact(std::string new_name, std::string new_last_name, std::string new_nickname, std::string new_phone_number,
			std::string new_secret);
	~Contact(void);
	std::string	getName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getPhoneNumber(void);
	std::string	getSecret(void);

  private:
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
};

#endif
