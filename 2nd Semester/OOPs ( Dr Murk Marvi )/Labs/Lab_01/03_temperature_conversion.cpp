#include<iostream>
using namespace std ;

int main(){
    double far ;
    cout << "Enter temperature in Fahrenheit : " ;
    cin >> far ;

    double cel = ( far - 32 ) / 1.8  ;

    cout << far << " Fahrenheit  is equal to " << cel << " in Celsius." << endl ;  
    return 0;
}