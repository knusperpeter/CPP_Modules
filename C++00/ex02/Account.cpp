#include <string>
#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static int _accountIndexCounter = 0;

void displayTimestamp(){
	std::time_t now = std::time(NULL);
	char buf[18];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", std::localtime(&now));
	std::cout << buf;
}

Account::Account(int initial_deposit){
	_accountIndex = _accountIndexCounter++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account(){
	displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts(){
	return _nbAccounts;
}

int	Account::getTotalAmount(){
	return _totalAmount;
}

int	Account::getNbDeposits(){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(){
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(){
	displayTimestamp();
	std::cout	<< " accounts:" << getNbAccounts() \
				<< ";total:" << getTotalAmount() \
				<< ";deposits:" << getNbDeposits() \
				<< ";withdrawals:" << getNbWithdrawals() \
				<< std::endl;
}

void Account::makeDeposit(int deposit){
	displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << _amount \
				<< ";deposit:" << deposit;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<< ";amount:" << _amount \
				<< ";nb_deposits:" << _nbDeposits \
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << _amount \
				<< ";withdrawal:";
	if (_amount >= withdrawal)
		std::cout	<< withdrawal;
	else{
		std::cout << "refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout	<< ";amount:" << _amount \
				<< ";nb_withdrawals:" << _nbWithdrawals \
				<< std::endl;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals \
				<< std::endl;
}
