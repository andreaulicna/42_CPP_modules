/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:05:28 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/10 19:40:37 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Constructor - no input argument */
Account::Account(void)
{
	return ;
}

/* Constructor - initial deposit as input argument */
Account::Account( int initial_deposit )
{
	// Set values for the newly created account
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// Adjust global values
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->checkAmount();

	// Print a message about the newly created account
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "created" << std::endl;
}

/* Destructor */
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "closed" << std::endl;
}
//
//// Getters
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
//
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}
//
//// Other methods - public
void	Account::makeDeposit( int deposit )
{
	// Adjust the account values that got affected by the deposit
	this->_amount += deposit;
	this->_nbDeposits += 1;

	// Adjust the global values
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	// Print a message confirming the deposit
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->checkAmount() - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	// Check for the case when there is not enough money to make the withdrawal
	if (withdrawal > this->checkAmount())
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->checkAmount() << ";"
			<< "withdrawal:refused" << std::endl;
		return (false);
	}

	// Adjust the account values that got affected by the withdrawal
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;

	// Adjust the global values
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	// Print a message confirming the withdrawal
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->checkAmount() + withdrawal << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Other methods - private
void	Account::_displayTimestamp( void )
{
	time_t	now;
	tm		*now_struct;

	now = time(0);
	now_struct = localtime(&now);
	std::cout << "[" << 1900 + now_struct->tm_year
		<< std::setfill('0') << std::setw(2) << 1 + now_struct->tm_mon
		<< std::setfill('0') << std::setw(2) << now_struct->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << now_struct->tm_hour
		<< std::setfill('0') << std::setw(2) << now_struct->tm_min
		<< std::setfill('0') << std::setw(2) << now_struct->tm_sec << "] ";
}