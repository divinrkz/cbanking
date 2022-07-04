#include <string>

using namespace std;

class Account
{
private:
    string bankName;
    int accountNumber;
    char accountHolder[100];
    double accountBalance;

public:
    Account();
    void createAccount();
}