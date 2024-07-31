#include<iostream>
using namespace std ;

void swapByPointers( double *a, double *b , double *c ) {
// This is to swap variables by left-shifting by 1 place. For Right-Shift ; start from right_hand most extreme value.
    int temp = *a ;
    *a = *b ;
    *b = *c ;
    *c = temp ;
}

int main(){
    double a , b , c ;
    cout << "Enter any 3 numbers : " ;
    cin >> a >> b >> c ;

    cout << "\nBefore swapping :-\n"
    << "a = " << a << " , b = " << b << " , c = " << c << endl ;

    swapByPointers( &a, &b, &c ) ; // We can also swap by using reference variables as for that we will just have to write prototype as => void swapByPointers( double &a , double &b , double &c ) and arguments as simple variables.

    cout << "After swapping :-\n"
    << "a = " << a << " , b = " << b << " , c = " << c << endl ;

    return 0;
}