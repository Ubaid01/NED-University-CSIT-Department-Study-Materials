#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void FIFO( vector<int>& rs , int& f ) {
    vector<int> mp(f, -1) ;
    int n = rs.size() , count = 0 , pf = 0 ;
    cout << nl << "The Page replacement process is: " << nl ;
	
    for (int i = 0; i < n; i++) {
        int k = 0 ;
        for (k = 0; k < f; k++) {
            if (mp[k] == rs[i])
                break;
        }

        if (k == f) {
            mp[count] = rs[i];
            count = (count + 1) % f;
            pf++;
        }

        for (int j = 0; j < f; j++)
            cout << "\t" << mp[j];

        if (k == f)
            cout << "\tPF No. " << pf;

        cout << nl;
    }

    cout << nl << "The number of page faults using FIFO are: " << pf << nl;
}

void LRU(vector<int>& rs , int& f ) {
    int n = rs.size() , next = 1 , pf = 0 ;
    vector<int> count( f , 0 ) , mp( f , -1 ) ;
    cout << nl << "The Page replacement process is: " << nl ;

    for( int i = 0 ; i < n ; i++ ) {
        bool flag = false ;
        for( int j = 0 ; j < f ; j++ ) {
            if( mp[j] == rs[i] ) {
                flag = true ;
                count[j] = next ; // How much recent it is. (time)
                next++ ;
                break ;
            }
        }

        // Find LRU.
        if( !flag ) {
            if( i < f ) {
                mp[i] = rs[i] ;
                count[i] = next ;
                next++ ;
            }
            else {
                int mn = 0 ;
                for( int j = 1 ; j < f ; j++ ) {
                    if( count[j] < count[mn] )
                        mn = j ;
                }

                mp[mn] = rs[i] ;
                count[mn] = next ;
                next++ ;
            }
            pf++ ;
        }
        for( int j = 0 ; j < f ; j++ )
            cout << "\t" << mp[j] ;

        if( !flag )
            cout << "\tPF No. " << pf ;
        cout << nl;
    }

    cout << nl << "The number of page faults using LRU are: " << pf << nl;
}

void MRU(vector<int>& rs , int& f ) {
	int n = rs.size() , next = 1 , pf = 0 ;
    vector<int> count( f , 0 ) , mp( f , -1 ) ;
    cout << nl << "The Page replacement process is: " << nl ;

    for( int i = 0 ; i < n ; i++ ) {
        bool flag = false ;
        for( int j = 0 ; j < f ; j++ ) {
            if( mp[j] == rs[i] ) {
                flag = true ;
                count[j] = next ; // How much recent it is. (time)
                next++ ;
                break ;
            }
        }

        // Find LRU.
        if( !flag ) {
            if( i < f ) {
                mp[i] = rs[i] ;
                count[i] = next ;
                next++ ;
            }
            else {
                int mx = 0 ;
                for( int j = 1 ; j < f ; j++ ) {
                    if( count[j] > count[mx] )
                        mx = j ;
                }

                mp[mx] = rs[i] ;
                count[mx] = next ;
                next++ ;
            }
            pf++ ;
        }

        for( int j = 0 ; j < f ; j++ )
            cout << "\t" << mp[j] ;

        if( !flag )
            cout << "\tPF No. " << pf ;
        cout << nl;
    }

    cout << nl << "The number of page faults using MRU are: " << pf << nl;
}

void Optimal( vector<int>& rs , int& f ) {
    int n = rs.size() , pf = 0 ;
    vector<int> mp( f , -1 ) ;

    cout << nl << "The Page replacement process is: " << nl ;
    for( int i = 0 ; i < n ; i++ ) {
        bool flag = false ;
        for( int j = 0 ; j < f ; j++ ) {
            if( rs[i] == mp[j] ) {
                flag = true ;
                break ;
            }
        }

        if( !flag ) {
            pf++ ;
            int idx = -1 ;
            for( int j = 0 ; j < f ; j++ ) {
                if( mp[j] == -1 ) {
                    idx = j ;
                    break ;
                }
            }
            if( idx == -1 ) {
               pair<int , int> far = { 0 , -1 } ;
               for( int j = 0 ; j < f ; j++ ) {
                    int k = i + 1 ;
                    while( k < n && mp[j] != rs[k] )
                        k++ ;
                    
                    if( k > far.first ) {
                        far.first = k ;
                        far.second = j ;
                    }
               }
               idx = far.second ;
            }
            

            mp[idx] = rs[i] ;   
        }
        for( int j = 0 ; j < f ; j++ )
            cout << "\t" << mp[j] ;

        if( !flag )
            cout << "\tPF No. " << pf ;
        cout << nl;
    }
    cout << nl << "The number of page faults using Optimal are: " << pf << nl;
}

int main() {
    int n , f ;
    cout << "Enter the length of reference string: ";
    cin >> n;

    vector<int> rs(n) ;
    cout << "Enter the reference string:" << nl ;
    for (int i = 0; i < n; i++)
        cin >> rs[i];
 
    cout << "Enter number of frames: ";
    cin >> f;
	
    int ops = 1 ;
    while( ops <= 4 ) {
        if( ops == 1 ) FIFO(rs, f) ;
        else if( ops == 2 ) LRU(rs, f) ;
        else if( ops == 3 ) MRU(rs, f) ;
        else if( ops == 4 ) Optimal(rs, f) ;
        ops++ ;
    }
    return 0;
}