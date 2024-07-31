#include<iostream>
#include<exception>
using namespace std ;

class String {
        char *str ;
        int length ;
    public:
        String( ) { } // My additional addition
        String( const char *msg ) {
            length = 0 ;
            while( msg[ length ] != '\0' )
                length++ ;
            
            str = new char[ length + 1 ] ; // For Null Character
            for( int i = 0 ; i < length ; i++ )
                str[ i ] = msg[ i ] ;
            
            str[ length ] = '\0' ; // Fixing the null character assignment ; I did + 1 also
        }
        String( const String& other ) {
            // delete[] str ; // Cause of error
            length = other.length ;
            str = new char[ length + 1 ] ; 
            for( int i = 0 ; i < length ; i++ )
                str[ i ] = other.str[ i ] ;
            
            str[ length ] = '\0' ;
        }

        ~String() { delete[] str ; } 
        char getCharAt( int index ) { 
            if( index >= 0 && index < length )
                return str[ index ] ;
            else    
                throw out_of_range("Index is out of range!") ;
        }
        void display( ) {
            for( int i = 0 ; i < length ; i++ )
                cout << str[ i ] ;
            cout << endl ;
        }

        bool operator==( const String& other ) {
            if( length != other.length )
                return false ;
            
            for( int i = 0 ; i < length ; i++ ) {
                if( str[ i ] != other.str[ i ] )
                    return false ;
            }
            return true ;
        }

        String operator+( const String& other ) { 
            String temp ;
            int newLen = length + other.length;
            temp.length = newLen ;
            temp.str = new char[ newLen + 1 ] ;
            for( int i = 0 ; i < length ; i++ )
                temp.str[i] = str[ i ] ;
            int k = 0;
            for( int i = length ; i < newLen ; i++ )
                temp.str[i] = other.str[ k++ ] ;

            return temp ;

            // // OR 
            // char* newStr = new char[newLen + 1];

            // for (int i = 0; i < length; i++)
            //     newStr[i] = str[i];
            // 
            // /*for (int i = 0; i < other.length; i++)
            // newStr[length + i] = other.str[i];*/

            // newStr[newLen] = '\0';

            // return String(newStr); // This was correct as now we don't need to make temp.
        }
} ;
int main(){
    try {
        String s1("Ali") ;
        String s2("Noman") ;
        cout << ( ( s1 == s2 ) ? "True" : "False" ) << endl ;
        cout << s2.getCharAt( 2 ) << endl ;
        String s3 = s1 + s2 ;
        s3.display( ) ;
    }
    catch( const exception& s1 ) {
        cout << s1.what() << endl ;
    }
    return 0;
}