/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:15:56 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/02/11 18:47:06 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isAlphaString(std::string str)
{
	if (str.empty())
	{
		return (false);
	}
	std::string::iterator it = str.begin();
	while (it != str.end())
	{
		if (!(std::isalpha(*it) || std::isspace(*it)))
		{
			return (false);
		}
		it++;
	}
	return (true);
}

bool isDigitString(std::string str)
{
	if (str.empty())
	{
		return (false);
	}
	std::string::iterator it = str.begin();
	while (it < str.end())
	{
		if (!std::isdigit(static_cast<unsigned char>(*it)))
		{
			return (false);
		}
		it++;
	}
	return (true);
}
