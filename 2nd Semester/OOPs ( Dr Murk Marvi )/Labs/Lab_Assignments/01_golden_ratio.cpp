#include<iostream>
#include<cmath>
using namespace std ;

int main(){
    double A , B , golden_ratio = 1.618 ;
    cout << "Enter any 2 numbers : " ;
    cin >> A >> B ;

    if( A < B ) { // As it is mentioned that ratio of the sum of the two numbers to the larger number.
        double temp = A ;
        A = B ;
        B = temp ;
    }
    double check_1 = round( ( ( A + B ) / A ) * 1000 ) / 1000 ; // 1st shift decimal to right then roundoff and again divide to get original number.
    // OR can also use  if (abs(result - golden_ratio) < 0.001 )
    double check_2 = round( ( A / B ) * 1000) / 1000 ; 
    // double exp = round( ( ( 1 + sqrt(5) ) / 2 ) * 1000 ) / 1000 ;
    // if( exp == golden_ratio )
    if( check_1 == golden_ratio && check_2 == golden_ratio )
        cout << "Given numbers are in golden ratio." ;
    else 
        cout << "Given numbers are NOT in golden ratio." ;
    return 0;
}