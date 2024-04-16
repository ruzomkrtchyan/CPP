#include "Account.hpp"
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account :: Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	_totalAmount += initial_deposit;
	std::cout << "created"<<std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed"<<std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	seconds;
	struct tm	*timeinfo;

	seconds = time(NULL);
	timeinfo = localtime(&seconds);
	std::cout << "[" << timeinfo->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
	std::cout << "_" << std::setfill('0') << std::setw(2) <<timeinfo->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) <<timeinfo->tm_min;
	std::cout << std::setfill('0') << std::setw(2) <<timeinfo->tm_sec << "]";

}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex <<";";
	std::cout << "p_amount:" <<  _amount << ";";
	std::cout << "deposits:"<< deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:"<< _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl; 
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawals:" <<withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal; 
	std::cout << "amount:"<< _amount << ";";
	std::cout << "nb_withdrawal:" << _nbWithdrawals << std::endl;
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (1);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" <<  _accountIndex <<";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

