#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string accountNo;
    string accountName;
    float balance;

public:
    Account(string accNo = "", string accName = "", float bal = 0.0)
        : accountNo(accNo), accountName(accName), balance(bal) {}

    void setAccountNo(const string &accNo) { accountNo = accNo; }
    string getAccountNo() const { return accountNo; }

    void setAccountName(const string &accName) { accountName = accName; }
    string getAccountName() const { return accountName; }

    void setBalance(float bal) { balance = bal; }
    float getBalance() const { return balance; }
};

class CurrentAccount : public Account
{
public:
    static const int serviceCharge = 100;
    static const int accountPrefix = 100;
    static int nextAccount;

    CurrentAccount(string accNo = "", string accName = "", float bal = 0.0)
        : Account(accNo, accName, bal) {}

    static int nextAccountNo() { return accountPrefix + nextAccount++; }
};

int CurrentAccount::nextAccount = 1;

class SavingsAccount : public Account
{
protected:
    float interestRate;
    float monthlyDepositAmount;

public:
    static const int accountPrefix = 200;
    static int nextAccount;

    SavingsAccount(string accNo = "", string accName = "", float bal = 0.0, float rate = 0.0, float monthlyDep = 0.0)
        : Account(accNo, accName, bal), interestRate(rate), monthlyDepositAmount(monthlyDep) {}

    void setInterestRate(float rate) { interestRate = rate; }
    float getInterestRate() const { return interestRate; }

    void setMonthlyDepositAmount(float amount) { monthlyDepositAmount = amount; }
    float getMonthlyDepositAmount() const { return monthlyDepositAmount; }

    static int nextAccountNo() { return accountPrefix + nextAccount++; }
};

int SavingsAccount::nextAccount = 1;

class MonthlyDepositScheme : public Account
{
protected:
    float interestRate;
    float monthlyDepositAmount;

public:
    static const int accountPrefix = 300;
    static int nextAccount;

    MonthlyDepositScheme(string accNo = "", string accName = "", float bal = 0.0, float rate = 0.0, float monthlyDep = 0.0)
        : Account(accNo, accName, bal), interestRate(rate), monthlyDepositAmount(monthlyDep) {}

    void setInterestRate(float rate) { interestRate = rate; }
    float getInterestRate() const { return interestRate; }

    void setMonthlyDepositAmount(float amount) { monthlyDepositAmount = amount; }
    float getMonthlyDepositAmount() const { return monthlyDepositAmount; }

    static int nextAccountNo() { return accountPrefix + nextAccount++; }
};

int MonthlyDepositScheme::nextAccount = 1;


class LoanAccount : public Account
{
protected:
    float interestRate;
    float monthlyDepositAmount;

public:
    static const int accountPrefix = 900;
    static int nextAccount;

    LoanAccount(string accNo = "", string accName = "", float bal = 0.0, float rate = 0.0, float monthlyDep = 0.0)
        : Account(accNo, accName, bal), interestRate(rate), monthlyDepositAmount(monthlyDep) {}

    void setInterestRate(float rate) { interestRate = rate; }
    float getInterestRate() const { return interestRate; }

    void setMonthlyDepositAmount(float amount) { monthlyDepositAmount = amount; }
    float getMonthlyDepositAmount() const { return monthlyDepositAmount; }

    static int nextAccountNo() { return accountPrefix + nextAccount++; }
};

int LoanAccount::nextAccount = 1;


class TwoYearMDS : public MonthlyDepositScheme
{
    float maximumInterest;

public:
    void setMaximumInterest(float maxInterest) { maximumInterest = maxInterest; }
    float getMaximumInterest() const { return maximumInterest; }
};

class FiveYearMDS : public MonthlyDepositScheme
{
    float maximumInterest;

public:
    void setMaximumInterest(float maxInterest) { maximumInterest = maxInterest; }
    float getMaximumInterest() const { return maximumInterest; }
};

class InitialDepositMDS : public MonthlyDepositScheme
{
    float maximumInterest;
    float initialDepositAmount;

public:
    void setMaximumInterest(float maxInterest) { maximumInterest = maxInterest; }
    float getMaximumInterest() const { return maximumInterest; }

    void setInitialDepositAmount(float amount) { initialDepositAmount = amount; }
    float getInitialDepositAmount() const { return initialDepositAmount; }
};

int main()
{

    CurrentAccount currAcc("1001", "John Doe", 5000.0);
    cout << "Current Account No: " << currAcc.getAccountNo() << endl;
    cout << "Account Name: " << currAcc.getAccountName() << endl;
    cout << "Balance: " << currAcc.getBalance() << endl;

    return 0;
}
