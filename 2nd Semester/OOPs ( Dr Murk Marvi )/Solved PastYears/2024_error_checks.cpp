#include<iostream>
#include<vector>
#include<fstream>
using namespace std ;

class MathUtility {
    public:
        static int divide( int a , int b ) {
            if( b == 0 ) {
                cout << "Division by zero error." ; exit(1); }
            
            return a / b ;
        }
} ;

string processString( string msg ) {
    cout << "Original Message : " << msg << endl ;
    int index = 0 ;
    while( msg[index] != '\0' ) {
        msg[index] += 2 ; index++;
    }
    return msg ;
}

class Vehicle {
    public:
        Vehicle( ) { cout << "Vehicle constructor called." << endl ; }
        virtual ~Vehicle() { cout << "Vehicle destructor called." << endl ; }
        virtual void display() { cout << "Displaying Vehicle." << endl ; }

} ;

class Car : public Vehicle {
    public:
        Car( ) { cout << "Car constructor called." << endl ; }
        ~Car() { cout << "Car destructor called." << endl ; }
        void display() { cout << "Displaying Car." << endl ; }
} ;

class SquareArea {
    float sideLength;
    public:
    // Here error was that default constructor was also provided so there were 2 constructors with same arguments ambiguity.
        // SquareArea( ) : sideLength( 0 ) { }
        SquareArea( float squareLength = 0 ) : sideLength( sideLength ) { }
        void setSideLength( float f ) { sideLength = f ; }
        float calculateArea( ) { return sideLength * sideLength ; }
} ;

int main(){
    // vector<int> v ; vector<int> w(11) ;
    // v.push_back( 1 ) ; v.push_back( 2 ) ; v.push_back( 3 ) ; 
    // w.push_back( 1 ) ; w.push_back( 2 ) ; w.push_back( 3 ) ;
    // cout << "Size of v : " << v.size() << endl ;
    // cout << "Size of w : " << w.size() << endl ;

    // cout << MathUtility::divide( 10 , 2 ) << endl 
    // << MathUtility::divide( 8 , 0 ) << endl ;

    // string line ;
    // ofstream objectFile("text.txt") ; 
    // if( !objectFile ) {
    //     cerr << "Error opening file!" << endl ; return 1 ;
    // }
    // objectFile << "Good Luck!" << endl ;
    // // objectFile >> line ; // This line will give error as we have made an ofstream not ifstream
    // objectFile.close( ) ;
    // ifstream inFile("text.txt") ;
    // if( !inFile ) {
    //     cerr << "Error opening file!" << endl ; return 1 ;
    // }
    // inFile >> line ;
    // cout << "Line = " << line << endl ;
    // inFile.close( ) ; 

    // string line = processString("OOPEXAM") ;
    // cout << "Encrypted Message: " << line << endl ; // Here error was that insertion stream operator was not used.

    // Vehicle* vehiclePtr = new Car( ) ;
    // vehiclePtr -> display( ) ;
    // delete vehiclePtr ;

    SquareArea ob ;
    ob.setSideLength( 12.0f ) ;
    cout << "Area is " << ob.calculateArea() << endl ;


    return 0;
}