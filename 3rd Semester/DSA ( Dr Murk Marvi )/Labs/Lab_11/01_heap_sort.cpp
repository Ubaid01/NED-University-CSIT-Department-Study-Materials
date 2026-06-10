#include<iostream>
#include<vector>
using namespace std ;

void heapifyDown( vector<int>& arr , int n , int i ) {
	int largest = i ;
	while( largest < n ) {
		int LC = 2 * i + 1 ;
		int RC = 2 * i + 2 ;
		
		if( LC < n && arr[LC] > arr[largest] )
			largest = LC ;
		if( RC < n && arr[RC] > arr[largest] )
			largest = RC ;
		
		if( largest == i )
			break ;
		
		swap( arr[i] , arr[largest] ) ;
		i = largest ;
	}
}

void heapSort( vector<int>& arr ) {
	int n = arr.size() ;
	for( int i = ( n - 1 ) / 2 ; i >= 0 ; i-- )
		heapifyDown( arr , n , i ) ;
	
	int index = n - 1 ;
	while( index > 0 ) {
		swap( arr[index] , arr[0] ) ; // As MaxHeap will have largest element on top so replace with currentIndex from start and apply heapify on remaining heapPart.
		heapifyDown( arr , index , 0 ) ;
		index-- ; 
	}
}

void display( vector<int>& arr ) {
	for( int& n : arr )
		cout << n << " " ;
	cout << endl ;
}

int main() {
	vector<int> arr = { 15 , 29 , 3 , 7 , 10 } ;
	vector<int> arr2 = { 29 , 3 , 7 , 10 } ;
	heapSort( arr ) ;
	display( arr ) ;
	heapSort( arr2 ) ;
	display( arr2 ) ;
	return 0 ;
}