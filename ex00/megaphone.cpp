#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for (std::string::iterator it = str.begin();
			it != str.end(); it++)
		{
			std::cout << static_cast<char>(toupper(*it));
		}
		std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
