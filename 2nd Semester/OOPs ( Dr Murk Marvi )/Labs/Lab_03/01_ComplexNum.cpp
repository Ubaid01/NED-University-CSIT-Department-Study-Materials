#include<iostream>

using namespace std; 

class Complex {
    private:
           float *real;
           float *img; 
    public:
           Complex( float r = 0 , float i = 0 ){
                real = new float( r ) ;
                img = new float( i ) ;
           }    
           Complex( const Complex& obj ) {
                real = new float( *obj. real ) ;
                img = new float( *obj.img ) ;
           }

           void modifyData( float r , float i ) {
                *real = r ; 
                *img = i ;
           }

           void display( ) {
                if( *img >= 0.0f )
                    cout << *real << " + " << *img << " i " << endl ;
                else
                    cout << *real << " - " << -(*img) << " i " << endl ;
           }
           
           ~Complex() {
               delete real ;
               delete img ; 
           }
};

int main() {
    float *real = new float; 
    float *img = new float; 
    
    cout << " Enter real part of complex number : " ;
    cin >> *real; 
    if ( cin.fail( ) ) {
        cout << "Invalid entry! Please enter a valid number\n" ;
        return 1 ;
    }
    cout << " Enter imaginary part of complex number : " ;
    cin >> *img; 
    if ( cin.fail( ) ) {
        cout << "Invalid entry! Please enter a valid number\n" ;
        return 1 ;
    }

    Complex c1( *real , *img );
    Complex *c2 = new Complex (c1) ;
    cout << "Complex number c1: ";
    c1.display( ) ;
    cout << "Complex number c2 (copied from c1): ";
    c2 -> display( ) ;

    c1.modifyData( 4.1 , -1.9 ) ;
    cout << "After Modifications :- " << endl << "C1 => ";
    c1.display( ) ;
    cout << "C2 => " ;
    c2 -> display( ) ;
    
    delete c2 ;
    delete real ; 
    delete img ; 

    return 0 ;
}