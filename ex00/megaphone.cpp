#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
	  std::string::iterator it;
		for (it = str.begin(); it != str.end(); it++)
		{
			std::cout << static_cast<char>(std::toupper(*it));
		}
		if (*(it + 1) != '\0')
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
