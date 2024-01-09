/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:05:28 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 23:07:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 8;
int	Account::_totalAmount = 20049;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Constructor - no input argument */
Account::Account(void)
{
	this->_accountIndex = 2;
	this->_amount = 1521;
	this->_nbDeposits = 1;
	this->_nbWithdrawals = 0;
	return ;
}

///* Constructor - initial deposit as input argument */
//Account::Account( int initial_deposit )
//{
//
//}
//
/* Destructor */
Account::~Account( void )
{
	return ;
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
//void	Account::makeDeposit( int deposit )
//{
//
//}
//
//bool	Account::makeWithdrawal( int withdrawal )
//{
//
//}
//
//int		Account::checkAmount( void ) const
//{
//
//}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
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