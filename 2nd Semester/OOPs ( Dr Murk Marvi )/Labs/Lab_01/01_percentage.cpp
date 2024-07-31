#include<iostream>
#include<string>
using namespace std ;

int main(){
    string roll_no ;
    double marks[5] , obt_marks = 0 ;
    cout << "Enter your roll number: " ;
    getline( cin , roll_no ) ; //  To handle whitespace buffer ( multi_words input possible )
    cout << "Enter obtained marks out of 100 in \n" ;

    for( auto &i : marks ) { // Used for-each loop to iterate through the whole marks container using "auto-i" which will compute the data-type of marks individual indices automatically . Also pass "i" as a reference so that its value can be modified in for-each loop like we are trying to print "1 , 2, 3... below for subjects. Expression " &i - &marks[0] " calculates the difference between the memory addresses of the current element and the first element.(offset) "
        cout << "Subject " << &i - &marks[0] + 1 << " : " ;
        cin >> i ;
        obt_marks += i ;
    }

    cout << "\nRoll No :- " << roll_no << endl 
    << "Obtained marks = " << obt_marks << endl
    << "Percentage = " << obt_marks / 5.0 << "%" << endl ; // Simply divided by 5.0 as 100 / 500 = 1 / 5
    return 0;
}