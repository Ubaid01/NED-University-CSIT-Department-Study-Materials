#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>
using namespace std ;

/* 
    Rules:
1. Every worker in the paid group must be paid at least their minimum wage expectation.
2. In the group, each worker's pay must be directly proportional to their quality. This means if a worker's quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

    The ratio tells us how much person is paying ; we have to pay everyone with same ratio.
Since we can't lower the wage so we will try to increase wage of lower-workers.
    Easy way to do this is if we add the qualities of 'k' person and directly multiply by that ratio like 10 + 5 = 15 * 70/10 = 105.
    For other ratios ; 30/5 , 50/20 so choose max i.e. '6' and 20 + 5 = 25 * 6 = 150.

    So we will take the ( Relative-wage ) Ratio and then sort based-on it. And then we will pick 'k' workers based on this ratio from start by being "Greedy". As we consider q = 1 ; ratio = 7 so it means this worker will only be paid '7' but if q = 1000 so it will be paid much-higher that's why we will pick sorted-ratio.
    Also we will then leave the ( n - k ) highest-quality workers as multiplying by ratio will make them pay higher. So for this we will use MaxHeap ( as we want to remove largest-quality workers )
*/

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    // Time = O( n * log(n) ) + O( n * log(k) ) ; Space = O(n)
    vector<pair<double,int>> ratioWages ;
    for( int i = 0 ; i < wage.size() ; i++ )
        ratioWages.push_back( { ( wage[i] * 1.0 ) / quality[i] , quality[i] } ) ;
    
    sort( ratioWages.begin(), ratioWages.end() ) ;
    priority_queue<int> maxHeap ;

   double res = numeric_limits<double>::max() ; // As for constraints after multiplying ; ans can be large.
    int totalQuality = 0 ; // Sum direct all 'k' people's quality for direct computation.

    for( int i = 0 ; i < ratioWages.size() ; i++ ) {
        double ratio = ratioWages[i].first ;
        int q = ratioWages[i].second ;

        maxHeap.push( q ) ;
        totalQuality += q ;

        // If size-increases 1st check it then == will directly run for all window >= k so not need to do check each time.
        if( maxHeap.size() > k ) {
            totalQuality -= maxHeap.top() ;
            maxHeap.pop() ;
        }

        if( maxHeap.size() == k )
            res = min( res , ratio * totalQuality ) ;
    }

    return res ;
}

int main(){
    vector<int> q1 = {10,20,5} , w1 = {70,50,30} ;
    vector<int> q2 = {3,1,10,10,1} , w2 = {4,8,2,2,7} ;

    cout << mincostToHireWorkers( q1 , w1 , 2 ) << endl ;
    cout << mincostToHireWorkers( q2 , w2 , 3 ) << endl ;
    return 0;
}