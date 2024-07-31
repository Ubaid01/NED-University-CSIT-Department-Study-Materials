#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std ;

class Game {
	private:
		int count_hits , pairs ;
	
	public :
		Game( int n = 0 )  {
			pairs = n ;
		}
		
		// inline to make it expandable at the main() and const to not modify it.
		inline int getCount ( ) const { return count_hits ; }
		inline int getPlayers( ) const { return pairs ; }

		void pairingTeams( ) {
			for( int i = 0 ; i < pairs ; i++ ) {
				int pair1 = rand() % 10 + 1 ;
				int pair2 = rand() % 10 + 1 ;
				cout << "Pair of numbers: " << endl 
				<< "Number1: " << pair1 << endl
				<< "Number2: " << pair2 << endl ;
				if( pair1 == pair2 ) {
					cout << "Enemy got hit by your team!\n" << endl ;
					count_hits++ ;
				}
				else {
					cout << "You got hit by enemy!\n" << endl ;
				}
			}
		}
} ;

int main( ) {
	srand( time( nullptr ) );
	int n ;
	n = rand() % 5 + 1 ; // Added 1 so range starts from 1 to 10.
	Game g(n) ;
	
	cout << "Total No.Of Players in your team are : " << g.getPlayers( ) << endl << endl ;
	g.pairingTeams() ;
	cout << "Game Over! " ;
	if( n / 2.0 < g.getCount() ) // If more than half hits are of ours
		cout << "You won." ;
	else 
		cout << "Enemy won." ;

	return 0 ;
}
