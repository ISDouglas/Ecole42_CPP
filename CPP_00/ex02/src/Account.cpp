#include "../includes/Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Definition and initialization of static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Private Constructor
Account::Account() {};

// Public Constructor
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount =  initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
			<< this->_amount << ";created" << std::endl;
}
// Destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
			<< this->_amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

// Private Member function
void	Account::_displayTimestamp()
{
	std::time_t now = std::time(nullptr);
	std::tm* 	ltm = std::localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year
			<< std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
			<< std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
			<< std::setw(2) << std::setfill('0') << ltm->tm_hour
			<< std::setw(2) << std::setfill('0') << ltm->tm_min
			<< std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}

// Public Member functions
int	Account::getNbAccounts()
{
	return _nbAccounts;
}
int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

int	Account::checkAmount() const
{
	return this->_amount;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"
			<< getTotalAmount() << ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
    _totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
    _totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
			<< this->_amount << ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

