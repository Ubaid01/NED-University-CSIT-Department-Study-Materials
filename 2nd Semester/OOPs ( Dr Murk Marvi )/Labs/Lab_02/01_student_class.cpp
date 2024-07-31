#include<iostream>
#include<limits>
#include<string>

using namespace std ;

class Student {
	private:
		string name , roll_no ;
		int semester ;
		char section ;
	
	public:
		Student( string n = "" , string r = "" , int s = 1 , char se = ' ' ) {
			setData( n , r , s , se ) ;
		}
		void setData( string n , string r , int s, char se ) {
			name = n ;
			roll_no = r ;
			if( s >= 1 && s <= 5 )
				semester =  s ;
			else {
				cout << "Invalid semester input!\n" ;
				exit(1) ;
			}
			section = se ;
		}
		inline char getSection() const { return section ; }

		void display() const {
			cout << "\nStudent Name = " << name
			<< "\nRoll No = " << roll_no 
			<< "\nSemester = " << semester 
			<< "  ;  Section = " << section << endl ;
		}
		
};

int main() {
	int n ;
	cout << "Enter no.of Students : " ;
	cin >> n ;
	cin.ignore() ;
	if( n <= 0 ) {
		cout << "Invalid number give !\n" ;
		return 1 ;
	}

	Student *s = new Student[n] ;

	for( int i = 0 ; i < n ;i++) {
		string name , roll ;
		int semester ;
		char section ;
		cout << "\nEnter details for Student " << i + 1 << ":\n" ;
		cout << "Enter student name : " ;
		getline( cin , name ) ;
		cout << "Enter student roll no : " ;
		getline( cin , roll ) ;
		cout << "Enter Semester number (1-5): " ;
		cin >> semester ;
		cout << "Enter Section (A/B/C): " ;
		cin >> section ;
		s[i].setData( name , roll , semester , section ) ;
		cin.ignore(numeric_limits<streamsize>::max(), '\n' ) ; // Remove all the buffer from stream
	}
	
	cout << "\nDetails of student having only Section 'A' :\n" ;
	for( int i = 0 ; i < 4 ; i++ ) {
		if( toupper( s[i].getSection( ) ) == 'A' ) 
			s[i].display() ;
	}
	delete[] s;

	return 0 ;
}