#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<unordered_map>
using namespace std ;

class MedianStream {
    private:
        priority_queue<int> maxHeap ;
        priority_queue<int , vector<int> , greater<int>> minHeap ;

        void balanceHeaps( ) {
            if( maxHeap.size() > minHeap.size() + 1 ) {
                minHeap.push( maxHeap.top() ) ;
                maxHeap.pop() ;
            }
            else if( minHeap.size() > maxHeap.size() ) {
                maxHeap.push( minHeap.top() ) ;
                minHeap.pop() ;
            }
        }

    public:
        void insert( int num ) {
            if( maxHeap.empty() || num <= maxHeap.top() ) 
                maxHeap.push( num ) ;
            else
                minHeap.push( num ) ;
            
            balanceHeaps() ;
        }

        void removeNum( int num ) {
            // if( maxHeap.empty() )
            //      return ;
        
            bool removed = false; // For duplicates ; as they will both were moved to 1-heap and size difference was huge.

            // if( num <= maxHeap.top() ) {
            //     int start = minHeap.top() ; // Mark the current-top of maxHeap.
            //     while ( !maxHeap.empty() && maxHeap.top() != num ) {
            //         minHeap.push( maxHeap.top() ) ;
            //         maxHeap.pop() ;
            //     }
            //     maxHeap.pop() ;

            //     while( minHeap.top() != start ) {
            //         maxHeap.push( minHeap.top() ) ;
            //         minHeap.pop() ;
            //     }
            // }
            // else {
            //     int start = maxHeap.top() ; 
            //     while ( !minHeap.empty() && minHeap.top() != num ) {
            //         maxHeap.push( minHeap.top() ) ;
            //         minHeap.pop() ;
            //     }
            //     minHeap.pop() ;

            //     while( maxHeap.top() != start ) {
            //         minHeap.push( maxHeap.top() ) ;
            //         maxHeap.pop() ;
            //     }
            // }

            if ( num <= maxHeap.top() ) {
                priority_queue<int> tempMax;
                while ( !maxHeap.empty() ) {
                    if ( maxHeap.top() == num && !removed )
                        removed = true ;
                    else
                        tempMax.push( maxHeap.top() ) ;
                    
                    maxHeap.pop();
                }
                maxHeap = tempMax;
            } 
            else {
                priority_queue<int, vector<int>, greater<int>> tempMin;
                while ( !minHeap.empty() ) {
                    if ( minHeap.top() == num && !removed )
                        removed = true ;
                    else
                        tempMin.push( minHeap.top() ) ;
                    
                    minHeap.pop();
                }
                minHeap = tempMin;
            }

            balanceHeaps() ;  
        }

        double top() {
            if( maxHeap.size() > minHeap.size() )
                return maxHeap.top() ;
            
            return ( maxHeap.top() + minHeap.top() ) / 2.0 ;
        }

        void check() {
            priority_queue<int> tempMax = maxHeap;
            priority_queue<int, vector<int>, greater<int>> tempMin = minHeap;
            cout << "MaxHeap = ";
            while (!tempMax.empty()) {
                cout << tempMax.top() << " ";
                tempMax.pop();
            }
            cout << " ; MinHeap = ";
            while (!tempMin.empty()) {
                cout << tempMin.top() << " ";
                tempMin.pop();
            }
            cout << endl;
        }
} ;

vector<double> slidingMedian( vector<int>& arr , int k ) {
    // Using multiset.
    vector<double> medians;
    multiset<int> window(arr.begin(), arr.begin() + k);
    
    auto mid = next(window.begin(), k / 2); // Iterator to the middle element
    
    for (int i = k; ; i++) {
        // If k is odd, take the middle element; if even, take the average of two middle elements
        double median = ( double(*mid) + *next( mid , (k % 2 == 0) ? -1 : 0 ) ) / 2;
        medians.push_back(median);
        
        if( i == arr.size() )
            break ;

        // Insert the next element and adjust the iterator 'mid'. The element naturally belongs to the "right half" of the multiset. So only removing lower terms will effect it directly.
        window.insert( arr[i] ) ;
        if ( arr[i] < *mid ) 
            mid--;
        
        // Remove the element going out of the window
        if ( arr[i - k] <= *mid ) 
            mid++;
        window.erase( window.lower_bound( arr[i - k]) ) ;
    }
    
    return medians;

    // Time = O( n * k * log(k) ) overall so TLE.
    // MedianStream med ;
    // int n = arr.size() ;
    // for( int i = 0 ; i < k ; i++ )
    //     med.insert( arr[i] ) ;
    
    // vector<double> res ;
    // res.push_back( med.top() ) ;

    // for( int i = k ; i < n ; i++ ) {
    //     med.insert( arr[i] ) ;
    //     med.removeNum( arr[i - k] ) ; // Remove element going out of window.
    //     res.push_back( med.top() ) ;
    // }
    // return res ;
}

void display( vector<double>& arr ) {
	for( double& n : arr )
		cout << n << " " ;
	cout << endl ;
}

int main(){
    vector<int> a = {1,3,-1,-3,5,3,6,7} ;
    vector<int> b = {1,2,3,4,2,3,1,4,2} ;
    vector<int> d = {1,8,8,3,5,2,2,6,6,7} ; // Changed removeNum due to duplicates then it took O( n * k * log(k) ) so TLE for my pq.
    vector<double> res = slidingMedian( a , 3 ) ;
    vector<double> res2 = slidingMedian( b , 3 ) ;
    vector<double> res3 = slidingMedian( d , 8 ) ;
    display( res ) ;
    display( res2 ) ;
    display( res3 ) ;
    return 0;
}