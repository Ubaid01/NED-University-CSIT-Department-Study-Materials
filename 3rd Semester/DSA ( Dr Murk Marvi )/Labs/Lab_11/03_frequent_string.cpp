#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std ;

void frequentString( string& str ) {
	unordered_map<char,int> hash ;
	for( char& ch : str )
		hash[ ch ]++ ;
	
	auto comp = []( pair<int,char>& a , pair<int,char>& b ) {
		if( a.first == b.first )
			return a.second > b.second ; // store smaller char for same frequency.
		
		return a.first < b.first ;
	} ;
	
	priority_queue< pair<int,char> , vector< pair<int,char>> , decltype( comp )> maxHeap( comp ) ;
	
	for( auto& itr : hash )
		maxHeap.push( { itr.second , itr.first } ) ;
	
	// int i = 0 ;
	str = "" ;
	while( !maxHeap.empty() ) {
		int freq = maxHeap.top().first ;
		char ch = maxHeap.top().second ;
		maxHeap.pop() ;
		
		// while( freq-- )
		// 	str[i++] = ch ;	
		
		str += string( freq , ch ) ; // Can do like this directly also.
	}
}


int main() {
	string str = "tree" ;
	string str2 = "cccaaa" ;
	string str3 = "Aabb" ;
	frequentString( str ) ;
	frequentString( str2 ) ;
	frequentString( str3 ) ;
	cout << str << endl ;
	cout << str2 << endl ;
	cout << str3 << endl ;
	return 0 ;
}