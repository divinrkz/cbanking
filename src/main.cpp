#include <iostream>
#include "Account.h"

using namespace std;

void displayBanner()
{
    cout << "------------------------------------------------" << endl;
    cout << "\tWELCOME TO BANKING SYSTEM" << endl;
    cout << "------------------------------------------------" << endl;
}

void createAccountMenu()
{
    cout << "1. Create an account." << endl;
    char name[100];

    cout << "Enter your fullName: ";
    cin.ignore();
    cin.getline(name, 100);

    float deposit;
    cout << "Your first deposit: ";
    cin >> deposit;

    Account account = Account(name, deposit);
    account.createAccount();

    cout << "Details " << account.getFullName() << endl;
}

void displayAllAccounts()
{
    cout << "Account " << endl;
    Account account;
    account.getAccounts();
}

void depositMenu()
{
    int accountNumber;
    float amount;
    cout << "Enter your account Number: ";
    cin >> accountNumber;

    cout << "Amount: ";
    cin >> amount;

    Account account;
    account.makeDeposit(accountNumber, amount);
}
void displayAccount()
{
    int accountNumber;
    cout << "Account Number: ";
    cin >> accountNumber;
    Account account;
    account.getAccount(accountNumber);
}

int main()
{
    srand((unsigned)time(0));

    displayBanner();
    cout << "Choose(1-9): " << endl;
    cout << "\t1. Create an account. " << endl;
    cout << "\t2. Display Account details. " << endl;
    cout << "\t3. Modify Account Details " << endl;
    cout << "\t4. Close your Account. " << endl;
    cout << "\t5. Make a Deposit " << endl;
    cout << "\t6. Make a withdraw " << endl;
    cout << "\t7. View all accounts " << endl;
    cout << "\t8. Check Balance " << endl;
    cout << "\t9. Exit" << endl;

    int choice;

    cout << "Your Choice(1-9): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("clear");
        displayBanner();
        createAccountMenu();

        break;

    case 2:
        system("clear");
        displayBanner();
        displayAccount();

        break;

    case 5:
        system("clear");
        displayBanner();
        depositMenu();

        break;

    case 7:
        system("clear");
        displayBanner();
        displayAllAccounts();

        break;

    default:
        break;
    }

    return 0;
}
