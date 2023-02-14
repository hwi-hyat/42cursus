#include"Account.hpp"
#include<iostream>
#include<iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

int Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::getTotalAmount()
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}



Account::Account( int initial_deposit ) {
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_accountIndex = this->getNbAccounts();

	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
	
	Account::_nbAccounts++;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
	Account::_nbAccounts--;
}



void Account::makeDeposit( int deposit ) {
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount + deposit
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:";

	if(withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return false;
	}

	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return true;
}

int Account::checkAmount( void ) const {
	return this->_amount;
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t realtime;

	realtime = std::time(NULL);
	std::cout << std::put_time(localtime(&realtime), "[%Y%m%d_%H%M%S] ");
}