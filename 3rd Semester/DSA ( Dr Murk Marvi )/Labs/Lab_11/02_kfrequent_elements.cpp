#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std ;

vector<int> kFrequentNums( vector<int>& arr , int k ) {
	unordered_map<int,int> hash ;
	for( int& num : arr )
		hash[ num ]++ ;
		
	priority_queue< pair<int,int> , vector< pair<int,int>> , greater<pair<int,int>>> minHeap ;
	int n = arr.size() ;
	
	for( auto& itr : hash ) {
		minHeap.push( { itr.second , itr.first } ) ;
		
		if( minHeap.size() > k ) 
			minHeap.pop() ;
	}
	
	vector<int> res ;
	while( !minHeap.empty() ) {
		res.push_back( minHeap.top().second ) ;
		minHeap.pop() ;
	}
	
	// reverse( res.begin() , res.end() ) ; // If want ordered.
	return res ;
}

void display( vector<int>& arr ) {
	for( int& n : arr )
		cout << n << " " ;
	cout << endl ;
}

int main() {
	vector<int> a = {1,1,1,2,2,3} ;
	vector<int> res = kFrequentNums( a , 2 ) ;
	display( res ) ;
	
	vector<int> b = {4,2,4,1,2,4,5,7,4,3,2,9,3} ;
	vector<int> res2 = kFrequentNums( b , 3 ) ;
	display( res2 ) ;
	return 0 ;
}