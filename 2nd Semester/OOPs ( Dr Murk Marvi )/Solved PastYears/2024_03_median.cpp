#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

template<typename T>
void sortArray( vector<T>& arr ) {
    for( int i = 0; i < arr.size() - 1 ; i++ ) {
        for( int j = 0 ; j < arr.size() - i - 1 ; j++ ) {
            if( arr[j] > arr[j + 1 ] )
                swap( arr[j] , arr[ j + 1 ] );
        }
    }
}

template<typename T>
double median( vector<T>& arr ) {
    int n = arr.size();
    sortArray( arr ) ;
    if( n % 2 == 0 )
        return ( arr[ ( n - 1 ) / 2.0 ] + arr[ ( n + 1 ) / 2.0 ] ) / 2.0 ;
    else
        return arr[  ( ( n + 1 ) / 2.0 ) - 1 ] ; // For array index ; we should also -1 as it is formula for normal sequence beginning with 1.
}

int main(){
    int n ;
    cout << "Enter no.of elements : " ;
    cin >> n ;
    vector<double> arr ;
    double num ;
    for( int i = 0; i < n ; i++ ) {
        cout << "Enter Element [" << i << "] : " ;
        cin >> num ; 
        arr.push_back( num ) ;
    }
    cout << "Median of double array : " << median( arr ) << endl ;
    return 0;
}