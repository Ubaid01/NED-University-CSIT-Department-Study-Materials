#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std ;

class Quiz {
    string ID ;
    char *responses ;
    int score ;
    char grade ;
    public :
        Quiz( string r = "", int sc = 0 , char ch = ' ' ) : ID(r) , responses(nullptr), score(sc) , grade(ch) { }

        void setData( string r , const char *s ) {
            ID = r ;
            delete[] responses ;
            responses = new char[strlen( s ) + 1 ] ;
            strcpy( responses , s ) ;
        }

        void processData( void ) ;
        void display( void ) {
            cout << ID << " " << responses << " " << score << " " << grade << endl ;
        }

        ~Quiz() {
            delete[] responses;
        }


} ;

void Quiz :: processData( void ) {
    int i = 0 ;
    while( responses[i] != '\0' ) {
        if( responses[i] == 'T' || responses[i] == 't' ) 
            score += 2 ;
        else if( responses[i] == 'F' || responses[i] == 'f' ) 
            score -= 1 ;
        i++ ;
    }
    double percent = ( (double) score / strlen( responses ) ) * 100.0 ;
    if( percent > 0 && percent < 60 )
        grade = 'F' ;
    else if ( percent >= 60 && percent < 70 )
        grade = 'D' ;
    else if ( percent >= 70 && percent < 80 )
        grade = 'C' ;
    else if ( percent >= 80 && percent < 90 )
        grade = 'B' ;
    // else if ( percent >= 90 && percent <= 100 )
    else if ( percent >= 90 )
        grade = 'A' ;
}
int main(){
    int questions , num ;
    cout << "Enter total no.of Students : " ;
    cin >> num ;
    cout << "Enter no.of question in quiz : " ;
    cin >> questions ;
    // Consume newline character left in input buffer
    cin.ignore( ) ;

    Quiz *stud = new Quiz[num];

    for ( int i = 0 ; i < num ; i++ ) {
        string id ;
        char *response = new char[questions + 1] ;
        cout << "Enter ID for student " << i + 1 << " : " ;
        cin >> id ;
        cout << "Enter responses for student " << i + 1 << ": ";
        cin.ignore( ) ;
        cin.getline( response , questions + 1 ) ;
        stud[i].setData( id , response ) ;
        delete[] response; // Free memory allocated for each local response
        stud[i].processData( ) ;
    }

    for ( int i = 0 ; i < num ; i++ ) {
        stud[i].display() ;
    }
    delete[] stud;

    return 0;
}