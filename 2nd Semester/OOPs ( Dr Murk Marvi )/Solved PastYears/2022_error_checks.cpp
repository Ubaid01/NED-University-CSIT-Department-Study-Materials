#include<iostream>
using namespace std ;

/* There is no error in this code and output will be 
    x = 2 count = 0
    x = 2 count = 1 ( incremented since it's a subsequent invocation of test<int> )
    x = 2.2 count = 0

    Since for "double" ; a different function will be used i.e. test( double& x ) instead of test( int& x ) so count will reset to 0 because test<double> is a different template instantiation
*/
template <typename T>
void test( const T& x ) {
    static int count = 0 ; 
    cout << "x = " << x << " count = " << count << endl ;
    ++count ;
}

class Base { virtual void display( ) = 0 ; } ;
class Child : public Base
{
    public:
        void display( ) {
            cout << "Never Give Up!!!" << endl ;
        }
} ;

class A {
    public:
        void square( int *x ) {
            (*x)++ ;
            *x = ( *x ) * (*x) ;
        }
        void square( int *x, int *y ) {
            cout << x << " " << y << endl ; // Even though ; it is passed as a pointer which will have it own memory address at different space separated by 8 bytes but it stores address of passed variable ; so if 1 is changed other will reflect also. Like both number passed. 
            --(*y) ;
            *x = ( *x ) * (*y) ;
        }
} ;

class Point {
    public:
        int xCoord , yCoord ;
        Point( int x = 0 , int y = 0 ) { xCoord = x; yCoord = y; }
        // Since here instead of adding ; we have added with assignment operator ; which will increment the original coordinates as well so both coordinates will be same i.e. p1 and p3
        Point operator+( const Point& right ) {
            // xCoord += right.xCoord ;
            // yCoord += right.yCoord ;
            int x , y ;
            x = xCoord + right.xCoord ; y = yCoord + right.yCoord ; // Corrected
            return Point( x , y );
        }
} ;

int main(){
    test<int>( 2 ) ;
    test<int>( 2 ) ;
    test<double>( 2.2 ) ;
    test<float>( 1.2 ) ;

    // Child obj ;
    // obj.display( ) ;
    // // "Base is an abstract class ( due to the pure virtual function display() ). So its objects cannot be instantiated directly . But can be made using pointer.
    // Base obj2 ;
    // obj2.display( ) ;

    // A obj ;
    // int number = 10 ;
    // obj.square( &number , &number ) ;
    // cout << number << endl ; // So output will be 81.

    // Point p1( 5 , 6 ) , p2( 1 , 1 ) , p3 ;
    // p3 = p1 + p2 ;
    // cout << "P1 : x = " << p1.xCoord << " ; y = " << p1.yCoord << endl 
    // << "P3 : x = " << p3.xCoord << " ; y = " << p3.yCoord << endl ;

    // int var = 0 ;
    // try {
    //     throw var ;
    // }
    // catch( int ex )
    // {
    //     ex += 10 ; // Modify the caught exception variable 'ex' to 0 + 10
    //     cout << "Error handling :: Val : " << var << " Ex: " << ex << endl ;
    //     // throw ; // Re-throwing the exception in "catch" which is wrong.
    // }

    return 0;
}