#include<iostream>
#include<iomanip>

using namespace std ;

class Bank {
	private:
		double balance , int_rate ;
		int transactions ;
	public:
		Bank( double initial_balance = 0 , double interest_rate = 0 ) {
			if ( initial_balance < 0 || interest_rate < 0 ) {
				cout << "Invalid initial balance or interest rate. Exiting...\n" ;
				exit(1) ;
			}
			balance = initial_balance ;
			int_rate = interest_rate / 100.0 ;
			transactions = 0 ;
		}

		double getBalance() const { return balance ; }

		int getTransactionCount() const { return transactions ; }

		void deposit( double amount ) {
			if ( amount > 0 ) {
				balance += amount ;
				transactions++;
			} 
			else
				cout << "Invalid deposit amount. Please enter a positive amount.\n";
		}

		void withdraw(double amount) {
			if (amount > 0 && amount <= balance) {
				balance -= amount;
				transactions++;
			} 
			else
				cout << "Invalid withdrawal amount or insufficient balance.\n";
		}

		void calculateInterest( int years ) {
			double interest = balance * int_rate * years;
			cout << "Interest earned over " << years << " years: " << fixed << setprecision(2) << interest << endl;
		}
};

int main() {
    double initial_balance, interest_rate;
    int years;

    cout << "Enter opening balance: ";
    cin >> initial_balance;
    cout << "Enter annual interest rate (%): ";
    cin >> interest_rate;


    Bank account(initial_balance, interest_rate);
    int choice;
    double amount;

    do {
        cout << "\nMenu:\n"
             << "1. Display Account Balance\n"
             << "2. Display Number of Transactions\n"
             << "3. Calculate Interest Earned\n"
             << "4. Make a Deposit\n"
             << "5. Make a Withdrawal\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Account Balance: " << account.getBalance() << endl;
                break;
            case 2:
                cout << "Number of Transactions = " << account.getTransactionCount() << endl;
                break;
            case 3:
                cout << "Enter number of years: ";
                cin >> years ;
                account.calculateInterest(years) ;
                break ;
            case 4:
                cout << "Enter deposit amount: " ;
                cin >> amount ;
                account.deposit(amount) ;
                break ;
            case 5:
                cout << "Enter withdrawal amount: " ;
                cin >> amount ;
                account.withdraw(amount) ;
                break ;
            case 6:
                cout << "Exiting program. Goodbye!\n" ;
                break ;
            default:
                cout << "Invalid choice. Please try again.\n" ;
				break ;
        }
    } while (choice != 6);

    return 0;
}
