#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() :
    _accountIndex(
        _nbAccounts++), // This is absolutely not a good way to assign an
                        // account index, but it works for the subject
    _amount(0), _nbDeposits(0), _nbWithdrawals(0) { }

Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
    _nbWithdrawals(0) {
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
              << std::endl;
    --_nbAccounts;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int deposit) {
    if (deposit > _amount) {
        return false;
    }
    _amount -= deposit;
    _totalAmount -= deposit;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    return true;
}

void Account::_displayTimestamp() {
    const time_t     now       = time(NULL);
    const struct tm *time_info = localtime(&now);
    char             buffer[128];

    strftime(buffer, 128, "[%Y%m%d_%H%M%S]", time_info);
    std::cout << buffer;
}

int Account::checkAmount() const {
    return _amount;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits() << ";withdrawals"
              << getNbWithdrawals() << std::endl;
}
