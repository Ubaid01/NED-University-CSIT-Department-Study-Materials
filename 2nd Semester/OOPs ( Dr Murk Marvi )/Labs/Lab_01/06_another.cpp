#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;

class Bank {
    private :
        string accountNumber , accountType ;
        char code ;
        double balance ;
    public :
        static int count ;
        Bank( string a = "" , char c = ' ' , string acc_type = "" , double m = 0 ) { }
        void setData( string a , char c , string acc_type , double m ) {
            accountNumber = a ;
            code = c ;
            accountType = acc_type ;
            balance = m ;
            count++ ;
        }

        double computeFee( double amount ) {
            double withdrawalFee ;
            if( accountType == "savings ")
                withdrawalFee = amount * 0.02; // 2 % of withdrawal amount
            else 
                withdrawalFee = 100 ; // fixed fees of 100
            if ( amount > 50000 ) {
                withdrawalFee += amount * 0.05; // 5 % add-on after 50k transaction
            }
            balance -= ( amount + withdrawalFee ) ;
            cout << "Tax + Fees = " << withdrawalFee << endl ;
            return balance ;
        }

        string getAccountNumber( void ) {  return accountNumber ; }

        double getBalance( void ) {  return balance ; }

        void checkAccounts( ) {
            cout << "Account Number = " << accountNumber
            << "\tAccount Type = " << accountType 
            << "\nBalance = " << balance << endl ;
        }

} ;

int Bank :: count = 0 ;

int main(){
    int opt ;
    Bank s[20] ;
    cout << "Welcome to Village New Online Banking System :- \n" ;
    do {
        string account_type , acc_num ;
        double amount ;
        char code ;
        int i = s -> count ;
        // cout << "Count = " << s -> count << endl ; // To test
        cout << "\n1. Add Account\n" 
        << "2. Display All Accounts\n" 
        << "3. Withdraw Balance\n"
        << "4. Check Balance\n"
        << "0. Exit\n" << endl 
        << "Enter the option number : " ;
        cin >> opt ;
        cin.ignore( ) ;
        switch( opt ) {
            case 1 :
                cout << "Enter your account type (savings or current): " ;
                getline( cin , account_type ) ;
                cout << "Enter your deposited balance : " ;
                cin >> amount ;
                cin.ignore( ) ;
                // Another way to lower "string" class.
                for( auto &ch : account_type ) {
                    ch = tolower( ch ) ; 
                }

                if( account_type == "savings" ) {
                    cout << "Enter your savings account number: ";
                    getline( cin , acc_num ) ;
                    cout << "Enter the code (S): ";
                    cin >> code ;
                    s[ i ].setData( acc_num , code , account_type , amount ) ;
                    cout << "Account added successfully.\n" ;
                }
                else if( account_type == "current" ) {
                    cout << "Enter your current account number: " ;
                    getline( cin , acc_num ) ;
                    cout << "Enter the code (C): " ;
                    cin >> code ;
                    s[ i ].setData( acc_num , code , account_type , amount ) ;
                    cout << "Account added successfully.\n" ;
                }
                else 
                    cout << "Invalid account type. Please enter 'savings' or 'current'." << endl ;
                break ;

            case 2 :
                cout << "All Accounts are listed under :-\n" ;

                for( int a = 0 ; a < i ; a++ ) {
                    s[a].checkAccounts( ) ;
                }
                break ;
            case 3 :
                cout << "Enter your savings account number: ";
                getline( cin , acc_num ) ;
                for( int a = 0 ; a < i ; a++ ) {
                    if( acc_num == s[a].getAccountNumber( ) ) {
                        cout << "Enter the amount you want to withdraw: ";
                        cin >> amount ;

                        // Withdrawal Ranges
                        if ( amount <= 0 || amount > 100000) {
                            cout << "Invalid withdrawal amount. Please enter an amount b/w 0 and 100,000." << endl;
                            break ;
                        }

                        s[a].computeFee( amount ) ;
                        cout << "Withdrawal successful. Transaction fee: " << amount << ". Remaining balance: " << s[a].getBalance( ) << endl;
                    }
                }
                break ;
            case 4 :
                cout << "Enter your savings account number: ";
                getline( cin , acc_num ) ;
                for( int a = 0 ; a < i ; a++ ) {
                    if( acc_num == s[a].getAccountNumber( ) ) {
                        cout << "Your remaining balance = " << s[a].getBalance( ) << endl ;
                    }
                }
                break ;
            case 0 :
                cout << "Exiting..." << endl ;
                return -1 ;
        }
    } while( 1 ) ;

    return 0;
}