#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t rawtime;
    char buffer[80];

    time (&rawtime);
    struct tm * timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"[%Y%m%d_%H%M%S] ",timeinfo);
    cout << buffer;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    cout << "accounts:" << getNbAccounts();
    cout << ";total:" << getTotalAmount();
    cout << ";deposits:" << getNbDeposits();
    cout << ";withdrawals:" << getNbWithdrawals();
    cout << endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();

    cout << "index:" << _accountIndex;
    cout << ";amount:" << _amount;
    cout << ";deposits:" << _nbDeposits;
    cout << ";withdrawals:" << _nbWithdrawals;
    cout << endl;
}

Account::Account(void) {
    _accountIndex = _nbAccounts;
    Account::_nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    t::_nbAccounts++;
    _amount = initial_deposit;
    t::_totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

Account::~Account(void) {
    t::_nbAccounts--;
    t::_totalAmount -= _amount;


    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

void Account::makeDeposit(int deposit) {
    t::_totalAmount += deposit;
    _amount += deposit;
    _nbDeposits++;
    t::_totalNbDeposits++;

    _displayTimestamp();
    cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:";
    cout << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits;
    cout << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();

    cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";

    if (_amount < withdrawal) {
        cout << "refused" << endl;
        return 0;
    }

    t::_totalAmount -= withdrawal;
    t::_totalNbWithdrawals++;
    _nbWithdrawals++;
    _amount -= withdrawal;

    cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << endl;
    return 1;
}

int Account::checkAmount(void) const {
    return _totalAmount;
}

int  Account::getNbAccounts(void)    { return Account::_nbAccounts; }
int  Account::getTotalAmount(void)   { return Account::_totalAmount; }
int  Account::getNbDeposits(void)    { return Account::_totalNbDeposits; }
int  Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
