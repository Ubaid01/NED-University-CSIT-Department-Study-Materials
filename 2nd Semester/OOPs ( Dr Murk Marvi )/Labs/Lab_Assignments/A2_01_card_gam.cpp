#include<iostream>
#include<algorithm>
using namespace std ;

class Game {
    int num ;
    public :
        Game( int n = 0 ) : num( n ) { }
        void set_data( int n ) {
            num = n ;
        }
        int get_num() { return num ; }
        int sum_of_digits() {
            int sum = 0 , n = num ;
            while( n > 0 ) {
                sum += ( n % 10 ) ;
                n /= 10 ;
            }
            return sum ;
        }

} ;

void Sort( Game arr[] , int n ) {
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        for ( int j = 0 ; j < n - i - 1 ; j++ ) {
            if ( arr[j].sum_of_digits( ) > arr[j + 1].sum_of_digits( ) ) {
                Game temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// OR // Comparison function to sort Game objects based on num
bool compareGame(Game& g1, Game& g2) {
    return g1.sum_of_digits() < g2.sum_of_digits();
}

void display( Game arr[] , int len ) {
    for (int i = 0; i < len ; i++) {
        cout << "Sorted card " << i + 1 << " : " << arr[i].get_num() << endl ;
    }
}

int main(){
    int cards ;
    cout << "How many cards do you have : " ;
    cin >> cards ;
    Game g[cards] ;

    for( int i = 0 ; i < cards ; i++ ) {
        int n ;
        cout << "Enter no.of card " << i + 1 << " : " ;
        cin >> n ;
        g[i].set_data( n ) ;
    }

     // Sorting the array of Game objects using <algorithm> 
    // sort( g , g + cards, compareGame);

    Sort( g , cards ) ;
    cout << "\n" ;
    display( g , cards ) ;
    return 0;
}