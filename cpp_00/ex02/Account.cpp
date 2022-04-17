#include "Account.hpp"
#include <iomanip>
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void) {
	return _nbAccounts;
}

int		Account::getTotalAmount(void) {
	return _totalAmount;
}

int		Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount	+= deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (_amount - withdrawal < 0) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount	-= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void) {
	char buf[20];
	std::time_t t = time(NULL);
	std::tm temp;

	localtime_r(&t, &temp);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &temp);
	std::cout << "[" << buf << "] ";
}

Account::Account(int initial_deposit) {
	_accountIndex	= ++_nbAccounts - 1;
	_amount			= initial_deposit;
	_nbDeposits		= 0;
	_nbWithdrawals	= 0;
	_totalAmount	+= initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created";
	std::cout << std::endl;
};

Account::Account( void ) {
	std::cout << "constructor" << std::endl;
}

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits += _nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
};
