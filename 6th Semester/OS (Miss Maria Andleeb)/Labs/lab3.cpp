#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void FSCS( int n , vector<int>& prs ) {
   double avgWt , avgTat ;
   vector<int> wt( n , 0 ) , tat( n , 0 ) ;
   wt[0] = avgWt = 0 ; // Assumed 1st arrival is at t = 0. So in SJF sort could be wrong as the minimum WOULDN'T have arrived yet.
   tat[0] = avgTat = prs[0] ;
   
   for(int i = 1 ; i < n ;i++ ) { 
      wt[i] = wt[i - 1] + prs[i - 1] ; 
      tat[i] = tat[i - 1] + prs[i] ; 
      avgWt += wt[i];
      avgTat += tat[i];
   }
   
   avgWt /= n ;
   avgTat /= n ;
   cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << nl ; 
   for(int i = 0 ; i < n ; i++ )
      cout << nl << "\t   P" << i << " \t\t    " << prs[i] << " \t\t    " << wt[i] << " \t\t     " << tat[i] ;
      
   cout << nl << "Average Waiting Time -- " << avgWt << nl ; 
   cout << "Average Turnaround Time -- " << avgTat << nl ;
}

void SJF( int n , vector<int>& prs ) {
   vector<pair<int, int>> arr(n) ;
   for(int i = 0 ; i < n ; i++ )
      arr[i] = { prs[i] , i } ;
      
   sort( arr.begin() , arr.end() ) ;
   double avgWt , avgTat ;
   vector<int> wt( n , 0 ) , tat( n , 0 ) ;
   wt[0] = avgWt = 0 ;
   tat[0] = avgTat = arr[0].first ;
   
   for(int i = 1 ;i < n ;i++ ) { 
      wt[i] = wt[i - 1] + arr[i - 1].first ; 
      tat[i] = tat[i - 1] + arr[i].first ; 
      avgWt += wt[i];
      avgTat += tat[i];
   }
   
   avgWt /= n ;
   avgTat /= n ;
   cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << nl ; 
   for(int i = 0 ; i < n ;i++ )
      cout << nl << "\t   P" << arr[i].second << " \t\t    " << arr[i].first << " \t\t    " << wt[i] << " \t\t     " << tat[i] ;
      
   cout << nl << "Average Waiting Time -- " << avgWt << nl ; 
   cout << "Average Turnaround Time -- " << avgTat << nl ;
}

void Priority() {
   int n ;
   cout << "Enter the number of processes: " ;
   cin >> n ;
   
   vector<array<int, 3>> prs(n) ;
   for( int i = 0 ; i < n ; i++ ) {
      cout << "Enter the Burst Time & Priority of Process " << i << " : " ; 
      cin >> prs[i][0] >> prs[i][1] ;
      prs[i][2] = i ;
   }
         
   auto cmp = [&]( const array<int, 3>& a, const array<int, 3>& b ) {
      if( a[1] != b[1] )
         return a[1] < b[1] ;
      return a[2] < b[2] ;  
   } ;
   sort( prs.begin() , prs.end() , cmp ) ;
      
   double avgWt , avgTat ;
   vector<int> wt( n , 0 ) , tat( n , 0 ) ;
   wt[0] = avgWt = 0 ;
   tat[0] = avgTat = prs[0][0] ;
   
   for( int i = 1 ; i < n ; i++ ) { 
      wt[i] = wt[i - 1] + prs[i - 1][0] ; 
      tat[i] = tat[i - 1] + prs[i][0] ; 
      avgWt += wt[i];
      avgTat += tat[i];
   }
   
   avgWt /= n ;
   avgTat /= n ;
   cout << "\t PROCESS \tPRIORITY \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << nl ; 
   for(int i = 0 ; i < n ;i++ )
      cout << nl << "\t   P" << i << " \t\t    " << prs[i][1] << " \t\t    " << prs[i][0] << " \t\t    " << wt[i] << " \t\t     " << tat[i] ;
      
   cout << nl << "Average Waiting Time -- " << avgWt << nl ; 
   cout << "Average Turnaround Time -- " << avgTat << nl ;
}

void RoundRobin(int n, vector<int>& bt) {
   int tq ;
   cout << "Enter time quantum: " ;
   cin >> tq ;
   vector<int> rem_bt = bt ;
   vector<int> wt(n, 0), tat(n, 0);

   int time = 0;
   while (true) {
      bool done = true;

      for (int i = 0; i < n; i++) {
         if (rem_bt[i] > 0) {
               done = false;

               if ( rem_bt[i] > tq ) {
                  time += tq ;
                  rem_bt[i] -= tq ;
               } 
               else {
                  time += rem_bt[i] ;
                  wt[i] = time - bt[i] ;
                  rem_bt[i] = 0 ;
               }
         }
      }

      if (done)
         break;
   }

   double avgWt = 0, avgTat = 0;
   for ( int i = 0; i < n; i++ ) {
      tat[i] = bt[i] + wt[i];
      avgWt += wt[i];
      avgTat += tat[i];
   }
   avgWt /= n;
   avgTat /= n;

   cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME" << nl ; 
   for(int i = 0 ; i < n ; i++ )
      cout << nl << "\t   P" << i << " \t\t    " << bt[i] << " \t\t    " << wt[i] << " \t\t     " << tat[i] ;
      
   cout << nl << "Average Waiting Time -- " << avgWt << nl ; 
   cout << "Average Turnaround Time -- " << avgTat << nl ;
}

int main() {
   int n ;
   cout << "Enter the number of processes: " ;
   cin >> n ;
   
   vector<int> prs(n) ;
   cout << "Enter burst time for processes: " ; 
   for( int i = 0 ; i < n ; i++ )
   cin >> prs[i] ;
   
   // FSCS( n , prs ) ;
   // SJF( n , prs ) ;

   RoundRobin( n , prs ) ;

   //  Priority() ;
    return 0;
}

