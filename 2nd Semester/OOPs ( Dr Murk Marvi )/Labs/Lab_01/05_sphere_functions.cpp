#include<iostream>
#include<cmath>
using namespace std ;

double surfaceArea( double r ) {
    return 4 * M_PI * pow( r , 2 ) ; // Used pow for power function and M_PI "pre-defined macro" from cmath library 
}

double volume( double r ) {
    return ( 4.0 / 3.0 ) * M_PI * pow( r , 3 ) ; 
}
int main(){
    double radius ;
    cout << "Enter radius of sphere : " ;
    cin >> radius ;

    cout << "\nSurface Area Of Sphere : " << surfaceArea( radius ) << " cm^2" << endl ;
    cout << "Volume Of Sphere : " << volume( radius ) << " cm^3" << endl ;
    return 0;
}