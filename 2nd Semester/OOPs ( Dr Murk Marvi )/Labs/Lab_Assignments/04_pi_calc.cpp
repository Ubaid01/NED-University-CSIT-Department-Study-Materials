#include<iostream>
#include<cmath>
using namespace std ;

int main(){
    // int limit ;
    // cout << "Enter the limit upto which you want to know the value of pi using Leibniz formula : " ;
    // cin >> limit ;

    int n = 1 , turns = 0 ;
    double pi_val = 4.0 ;
    cout << "Value of pi from Leibniz formula is as \n" ;
    while( true ) {
        int sign = ( n % 2 != 0 ) ? -1 : 1; // Alternate the sign of the terms
        pi_val += ( 4.0 * sign ) / ( ( 2.0 * n ) + 1.0 ) ;
        n++ ;
        cout << n << " Sequence value = " << pi_val << endl ;
        // if( ( round( pi_val * 100 ) / 100 ) == 3.14 ) // Not reliable as it will search for the roundoff pi 3.14
        if( trunc( pi_val * 100 ) == 314 ) { // remove all the decimal part (like leading 0s)
            cout << "At " << n << " pi_value reaches approximately to 3.14 for 1st time.\n" ;
            break ;
        } 
    }
    return 0;
}