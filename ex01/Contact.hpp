#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class	Contact
{
	public:
		Contact (void);
		Contact (std::string new_name, std::string new_last_name,
		   std::string new_nickname, std::string new_phone_number,
		   std::string new_secret);
		~Contact (void);
		
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;
};

#endif
