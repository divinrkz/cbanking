#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

class Account
{
private:
    int accountNumber;
    char *fullName;
    float accountBalance;
    int generateAccountNumber();

public:
    Account(){};
    Account(char *fullName, float balance);
    void createAccount();
    void setAccountNumber(int accountNumber);
    void setFullName(char *fullName);
    void setAccountBalance(float accountBalance);
    Account getAccount(int accountNumber);
    vector<Account> getAccounts();
    string extractorToAccount(string line, string prop);
    char *getFullName();
    void makeDeposit(int accountNumber, float deposit);
};

Account::Account(char *fullName, float balance)
{
    this->accountNumber = generateAccountNumber();
    this->fullName = fullName;
    this->accountBalance = balance;
}

int Account::generateAccountNumber()
{
    return 10000 + (rand() % 100000);
}

char *Account::getFullName()
{
    return this->fullName;
}

void Account::createAccount()
{
    ofstream fout("db.txt", fstream::in | fstream::out | fstream::app);
    fout << "accountNumber:" << this->accountNumber << "|"
         << "fullName:" << this->fullName << "|"
         << "accountBalance:" << this->accountBalance << "|" << endl;

    cout << "Account created successfully!" << endl;
}

Account Account::getAccount(int accountNumber)
{
    ifstream inFile("db.txt");

    string line;

    Account account;
    while (inFile >> line)
    {

        string test = to_string(accountNumber);
        if (line.find(test) != string::npos)
        {
            cout << "AccountNumber: " << extractorToAccount(line, "accountNumber") << endl;

            cout << "AccountName: " << extractorToAccount(line, "fullName") << endl;
            cout << "AccountBalance: " << extractorToAccount(line, "accountBalance") << endl;

            account.setAccountNumber(stoi(extractorToAccount(line, "accountNumber")));
            account.setFullName(&extractorToAccount(line, "fullName")[0]);
            account.setAccountBalance(stoi(extractorToAccount(line, "accountBalance")));
        }
    }

    return account;
}

vector<Account> Account::getAccounts()
{
    ifstream inFile("db.txt");

    string word;

    vector<Account> accounts;
    while (inFile >> word)
    {
        Account account;
        cout << "AccountNumber: " << extractorToAccount(word, "accountNumber") << endl;
        cout << "AccountName: " << extractorToAccount(word, "fullName") << endl;
        cout << "AccountBalance: " << extractorToAccount(word, "accountBalance") << endl;

        account.setAccountNumber(stoi(extractorToAccount(word, "accountNumber")));
        account.setFullName(&extractorToAccount(word, "fullName")[0]);
        account.setAccountBalance(stoi(extractorToAccount(word, "accountBalance")));

        accounts.push_back(account);
        cout << endl;
    }

    return accounts;
}

string Account::extractorToAccount(string line, string prop)
{
    size_t found = line.find(prop);

    string strNew;
    if (found != string::npos)
    {
        string test = line.substr((found + prop.length()));
        unsigned first = test.find(":");
        unsigned last = test.find("|");
        strNew = test.substr(first + 1, (last - first) - 1);
    }
    return strNew;
}

void Account::makeDeposit(int accountNumber, float deposit)
{
    Account account = this->getAccount(accountNumber);

    vector<Account> accounts = this->getAccounts();
    cout << "Size: " << this->getAccounts().size() << endl;

    ofstream fout("db.txt");

    for (Account _account : accounts)
    {
        float udpated = _account.accountBalance;
        if (_account.accountNumber == accountNumber)
            udpated += deposit;

        cout << "My name is: " << _account.fullName << endl;

        fout << "accountNumber:" << _account.accountNumber << "|"
             << "fullName:" << _account.fullName << "|"
             << "accountBalance:" << udpated << "|" << endl;
    }
}

void Account::setAccountNumber(int accountNumber)
{
    this->accountNumber = accountNumber;
}

void Account::setFullName(char *fullName)
{
    this->fullName = fullName;
}

void Account::setAccountBalance(float balance)
{
    this->accountBalance = balance;
}