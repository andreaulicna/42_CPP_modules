/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:05:28 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/10 21:39:22 by aulicna          ###   ########.fr       */
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

/**
 * @brief	Constructor - no input argument.
*/
Account::Account(void)
{
	return ;
}

/**
 * @brief	Constructor - initial deposit as input argument.
 * 
 * First, it sets the values for the newly created account. Then it adjusts
 * the global values. And lastly, it prints a message confirming the creation
 * of an account.
 * 
 * @param	initial_deposit	initial deposit into the account
*/
Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts += 1;
	Account::_totalAmount += this->checkAmount();

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "created" << std::endl;
}

/**
 * @brief	Destructor.
*/
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "closed" << std::endl;
}

// Getters
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

/**
 * @brief	Displays the following information about the accounts: accounts,
 * total, deposits, withdrawals.
*/
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

// Other methods - public
/**
 * @brief	Makes a deposit into an account.
 * 
 * First, it adjust the account values that got affected by the deposit. Then
 * it adjust the appropriate global values. Finally, a message confirming
 * the deposit is printed.
 * 
 * @param	deposit	deposit to make
*/
void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits += 1;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->checkAmount() - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

/**
 * @brief	Makes a withdrawal from an account.
 * 
 * First, it checks whether there is enough money to make the withdrawal. If not
 * the withdrawal is refused.
 * 
 * If there is enough money, first, the account values that got affected by
 * the withdrawal are adjusted. Then the global ones are too. Lastly, a message
 * confirming the withdrawal is printed.
 * 
 * @param	withdrawal	withdrawal to make
*/
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->checkAmount())
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->checkAmount() << ";"
			<< "withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->checkAmount() + withdrawal << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

/**
 * @brief	Getter for the _amount member attribute of an account.
*/
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

/**
 * @brief	Displays the following information about an account: index, amount,
 * deposits, withdrawals.
*/
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Other methods - private
/**
 * @brief	Displays the current timestamp in [YYYYMMDD_HHMMSS] format.
 * total, deposit, withdrawals.
*/
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
