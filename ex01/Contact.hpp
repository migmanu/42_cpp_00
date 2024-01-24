#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class	Contact
{
	public:
		Contact ( void );
		Contact ( std::string name, int *nbr );
		~Contact ( void );
		
		std::string	contact_name;
		int			*contact_nbr;
};

#endif
