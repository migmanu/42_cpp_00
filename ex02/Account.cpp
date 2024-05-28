/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:21:20 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/28 22:46:33 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits  = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created"
			  << std::endl;

	return;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed"
			  << std::endl;

	return;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;

	return;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount
			  << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;

	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount;
	if (p_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;

		return false;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
			  << std::endl;

	return;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *localTime = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << buffer << "]";

	return;
}

Account::Account(void)
{
	return;
}
