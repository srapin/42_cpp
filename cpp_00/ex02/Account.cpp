/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:33:10 by srapin            #+#    #+#             */
/*   Updated: 2023/10/12 19:45:09 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account( int initial_deposit ) : Account()
{
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount<<";created\n";
}

Account::~Account( void )
{
    _displayTimestamp();

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" <<_accountIndex << ";p_amount:" 
		<< _amount << ";deposit:" << deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _amount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:"
		<< _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" 
		<< _amount << ";withdrawal:";
    if (withdrawal > _amount)
    {
        std::cout << "refused\n";
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    
    std::cout << withdrawal << ";amount:" << _amount <<
		";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}
int	Account::checkAmount( void ) const
{
    return _amount > 0;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" <<
	_amount << ";deposits:" << _nbDeposits << ";withdrawals:"
	<< _nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp( void )
{
    std::time_t time_now = std::time(nullptr);
	std::cout << std::put_time(std::localtime(&time_now), "[%Y%m%d_%OH%OM%OS] ");
}


Account::Account( void )
{
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts += 1;
    
}