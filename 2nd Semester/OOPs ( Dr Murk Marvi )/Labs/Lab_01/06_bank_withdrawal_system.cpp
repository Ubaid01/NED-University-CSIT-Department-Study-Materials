#include<iostream>
#include<string>
#include <algorithm> // for std::transform
#include <cctype> 
using namespace std ;

int main(){
    string account_type ;
    cout << "Enter your account type (savings or current): " ;
    getline( cin , account_type ) ;
    // Convert the entire string to lowercase
    transform(account_type.begin(), account_type.end(), account_type.begin(),
              [](unsigned char c) { return tolower(c); } ) ;

    double balance = 200000; // All users have 2 lakh
    double withdrawalAmount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> withdrawalAmount;

    // Withdrawal Ranges
    if (withdrawalAmount <= 0 || withdrawalAmount > 100000) {
        cout << "Invalid withdrawal amount. Please enter an amount b/w 0 and 100,000." << endl;
        return 1;
    }

    if (account_type == "savings") {
        string accountNumber ;
        char code ;
        cout << "Enter your savings account number: ";
        cin >> accountNumber;
        cout << "Enter the code (S): ";
        cin >> code;

        if( code == 'S' ) {
            double withdrawalFee = withdrawalAmount * 0.02; // 2 % of withdrawal amount
            if (withdrawalAmount > 50000) {
                withdrawalFee += withdrawalAmount * 0.05; // 5 % add-on after 50k transaction
            }
            balance -= (withdrawalAmount + withdrawalFee);

            cout << "Tax + Fees = " << withdrawalFee << endl ;
            cout << "Withdrawal successful. Transaction fee: " << withdrawalFee << ". Remaining balance: " << balance << endl;
        }
        else 
            cout << "Invalid code Entered !\n" ;
    } 
    else if (account_type == "current") {
        string accountNumber ;
        char code ;
        cout << "Enter your current account number: ";
        cin >> accountNumber;
        cout << "Enter the code (C): ";
        cin >> code;

        if( code == 'C' ) {
            double withdrawalFee = 100;
            if (withdrawalAmount > 50000) {
                withdrawalFee += withdrawalAmount * 0.05;
            }
            balance -= (withdrawalAmount + withdrawalFee);

            cout << "Tax + Fees = " << withdrawalFee << endl ;
            cout << "Withdrawal successful. Transaction fee: " << withdrawalFee << ". Remaining balance: " << balance << endl;
        }
        else 
            cout << "Invalid code Entered !\n" ;
    } 
    else
        cout << "Invalid account type. Please enter 'savings' or 'current'." << endl;

    return 0;
}