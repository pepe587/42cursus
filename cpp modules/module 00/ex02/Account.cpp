#include "Account.hpp"
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getNbDeposits(void)
{
	 return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


void	Account::_displayTimestamp(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    std::cout << "[" << time.tv_sec << "-" << time.tv_usec << "]";
}


void	Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";"
    << "total:" << Account::getTotalAmount() << ";"
    << "deposits:" << Account::getNbDeposits() << ";"
    << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
Account::Account(int initial_deposit)
{
    if (initial_deposit >= 0)
    {
        Account::_amount = initial_deposit;
        Account::_totalAmount += initial_deposit;
    }
    Account::_nbAccounts++;
    Account::_totalNbDeposits++;
    this->_displayTimestamp();
    this->_accountIndex = Account::getNbAccounts() - 1;
    std::cout << "index:" << this->_accountIndex
    << ";" << "amount:" << Account::checkAmount()
    << ";" << "created" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
    << "p_amount:" << Account::_amount << ";" << "deposit:"
    << deposit << ";" << "amount:" << Account::_amount + deposit
    << Account::getNbDeposits() << std::endl;
    this->_totalAmount += deposit;
    this->_amount += deposit;
    this->_totalNbDeposits++;
    this->_nbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
    << "p_amount:" << Account::_amount << ";" << "withdrawal:";
    if (withdrawal > Account::_amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    else
    {
        Account::_totalAmount -= withdrawal;
        Account::_amount -= withdrawal;
        Account::_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << withdrawal << ";" << "amount:" << _amount << ";"
        << "nb_withdrawal:" << Account::_totalNbWithdrawals << std::endl;
        return true;
    }
}

int Account::checkAmount(void) const
{
    return Account::_amount;
}


void	Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";"
    << "amount:" << Account::_amount << ";"
    << "deposits:" << Account::_nbDeposits << ";"
    << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

Account::~Account()
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";" << "amount:" << Account::checkAmount()
    << ";" << "closed" << std::endl;
    Account::_nbAccounts = 0;
    Account::_totalAmount = 0;
    Account::_totalNbDeposits = 0;
    Account::_totalNbWithdrawals = 0;
}