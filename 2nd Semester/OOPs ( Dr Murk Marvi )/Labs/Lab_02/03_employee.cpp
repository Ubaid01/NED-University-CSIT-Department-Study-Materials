#include <iostream>
#include <string>
#include <cstring>
#include <limits> 
#include <iomanip> 

using namespace std;

class Employee {
    private:
        char *firstName ; 
        string lastName ;
        double monthlySalary ;

    public:
        Employee( const char *first = nullptr , const string last = "" , double salary = 0 ) { }

        void setData( const char *first , const string last  , double salary ) {
            setFirstName(first) ;
            lastName = last ;
            monthlySalary = (salary >= 0) ? salary : 0 ;
        }

        void setFirstName(const char *first) {
            if (first) {
                // Allocating new memory and copy the input string
                firstName = new char[strlen(first) + 1];
                strcpy(firstName, first);
            } 
            else {
                // Set to empty string if nullptr is passed
                firstName = new char[1];
                firstName[0] = '\0';
            }
        }

        const char* getFirstName() const { return firstName ; }
        const string getLastName() const { return lastName ; }
        inline double getMonthlySalary() const { return monthlySalary ; }
        inline double getYearlySalary() const { return monthlySalary * 12 ; }

        void applyRaise( double percentage ) {
            if ( percentage > 0 ) {
                monthlySalary =  monthlySalary * ( 1 + percentage / 100.0 ) ;
            }
        }
 
        ~Employee() {
            delete[] firstName;
        }
} ;

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n ;
    cin.ignore( ) ;
    if ( n <= 0 ) {
        cout << "Invalid number of employees.\n";
        return 1;
    }
    Employee *emp = new Employee[n] ;

    for ( int i = 0 ; i < n ; i++ ) {
        string firstName ;  
        string lastName;
        double salary;
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        cout << "Enter first name: ";
        getline( cin , firstName ) ;
        cout << "Enter last name: ";
        getline(cin, lastName);
        cout << "Enter monthly salary: ";
        cin >> salary;
        
        const char* charPtr = firstName.c_str() ; // Convert string class object to C style string pointer
        emp[i].setData( charPtr , lastName , salary ) ;
        cin.ignore( numeric_limits<streamsize>::max( ) , '\n' ) ;
    }

    cout << "\nYearly Salaries:\n";
    for ( int i = 0 ; i < n ; i++ ) {
        cout << "Yearly Salary for " << emp[i].getFirstName() << " " << emp[i].getLastName()
             << ": $" << emp[i].getYearlySalary() << endl;
    }

    for ( int i = 0 ; i < n ; i++ ) {
        double raise ;
        cout << "\nEnter the increment % : " ;
        cin >> raise ;
        emp[i].applyRaise( raise ) ;
    }

    cout << "\nAfter salary raise:\n";
    for ( int i = 0 ; i < n ; i++ ) {
        cout << "Yearly Salary for " << emp[i].getFirstName() << " " << emp[i].getLastName()
             << ": $" << emp[i].getYearlySalary() << endl;
    }

    delete [] emp ;
    return 0;
}
