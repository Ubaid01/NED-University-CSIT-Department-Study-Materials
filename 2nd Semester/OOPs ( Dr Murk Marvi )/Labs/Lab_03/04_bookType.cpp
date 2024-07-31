#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_AUTHORS = 4 ;
const int MAX_BOOKS = 100 ;

class bookType {
    private:
        string title ;
        string authors[ MAX_AUTHORS ] ;
        string publisher ;
        string ISBN ;
        float price ;
        int numCopiesInStock ;
        int numAuthors ;
        int currentSet ;
        static int TotalBooks ;

    public:
        bookType();
        bookType( string t , string auth[] , int numAuth , string pub , string isbn , float p , int copies ) ;
        ~bookType() { } 

        void setTitle( string t ) ;
        void setAuthors( string auth[], int numAuth ) ;
        void setPublisher( string pub ) ;
        void setISBN( string isbn ) ;
        void setPrice( float p ) ;
        void setNumCopiesInStock( int copies ) ;

        string getTitle( ) const ;
        string* getAuthors( ) ; 
        string getPublisher( ) const ;
        string getISBN( ) const ;
        float getPrice( ) const ;
        int getNumCopiesInStock( ) const ;
        int getNumAuthors( ) const ;

        void showBookInfo( ) const ;
        void searchByTitle( string title ) const ;
        void searchByISBN( string isbn ) const ;
        void updateStock( int newStock ) ;
};

// Implementations of member functions outside the class

// Static Members
int bookType :: TotalBooks = 0 ;

// Constructors
bookType::bookType( ) {
    title = "" ;
    publisher = "" ;
    ISBN = "" ;
    price = 0.0f ;
    numCopiesInStock = 0 ;
    numAuthors = 0 ;
    currentSet = TotalBooks + 1 ;
    TotalBooks++ ;
}

bookType::bookType( string t , string auth[] , int numAuth , string pub , string isbn , float p , int copies ) {
    title = t ;
    setAuthors( auth , numAuth ) ;
    publisher = pub ;
    ISBN = isbn ;
    price = p ;
    numCopiesInStock = copies ;
}

// Setters
void bookType::setTitle( string t ) {
    title = t ;
}

void bookType::setAuthors( string auth[] , int numAuth ) {
    numAuthors = min( numAuth , MAX_AUTHORS ) ;
    for ( int i = 0 ; i < numAuthors ; i++ ) {
        authors[i] = auth[i];
    }
}

void bookType::setPublisher( string pub ) {
    publisher = pub ;
}

void bookType::setISBN( string isbn ) {
    ISBN = isbn ;
}

void bookType::setPrice( float p ) {
    price = p ;
}

void bookType::setNumCopiesInStock( int copies ) {
    numCopiesInStock = copies ;
}

// Getters
string bookType::getTitle( ) const {
    return title ;
}

string* bookType::getAuthors( ) {
    return authors ;
}

string bookType::getPublisher( ) const {
    return publisher ;
}

string bookType::getISBN( ) const {
    return ISBN ;
}

float bookType::getPrice( ) const {
    return price ;
}

int bookType::getNumCopiesInStock( ) const {
    return numCopiesInStock ;
}

int bookType::getNumAuthors( ) const {
    return numAuthors ;
}

// Others
void bookType::showBookInfo( ) const {
    cout << "\nTitle: " << title << endl
    << "Authors = ";
    for ( int i = 0 ; i < numAuthors ; i++ ) {
        cout << authors[i] ;
        if (i < numAuthors - 1) 
            cout << ", ";
    }
    cout << "\nPublisher = " << publisher << endl 
    << "ISBN = " << ISBN << endl
    << "Price = Rs " << price << endl
    << "Number of copies in stock = " << numCopiesInStock << endl;
}

void bookType::searchByTitle( string searchTitle ) const {

    if( getTitle( ) == searchTitle ) {
        cout << searchTitle << " Book found . Details are : \n" ;
        showBookInfo( ) ;
    }
    else 
        cout << searchTitle << " Book Not Found"<< endl ;
}

void bookType::searchByISBN( string searchISBN ) const {

    if( getISBN( ) == searchISBN ) {
        cout << searchISBN << " Book found . Details are : " ;
        showBookInfo( ) ;
    }
    else
        cout << searchISBN << " ISBN-Number Book Not Found"<< endl ;
}

void bookType::updateStock( int newStock ) {
    numCopiesInStock = newStock ;
}

int main() {
    bookType* books[MAX_BOOKS] = { nullptr } ;
    int bookCount = 0;

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add a new book\n";
        cout << "2. Show all books\n";
        cout << "3. Search by title\n";
        cout << "4. Search by ISBN\n";
        cout << "5. Update stock of a book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (bookCount < MAX_BOOKS) {
                cin.ignore(); // clear input buffer
                string title;
                cout << "Title: ";
                getline(cin, title);
                
                int numAuthors;
                cout << "Number of authors: ";
                cin >> numAuthors;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
                if (numAuthors < 0 || numAuthors > MAX_AUTHORS) {
                    cout << "Invalid number of authors. Maximum allowed authors: " << MAX_AUTHORS << endl;
                    break;
                }
                string authors[MAX_AUTHORS];
                for (int i = 0; i < numAuthors; i++) {
                    cout << "Author " << i + 1 << ": ";
                    getline(cin, authors[i]);
                }

                string publisher;
                cout << "Publisher: ";
                getline(cin, publisher);
                string isbn;
                cout << "ISBN: ";
                getline(cin, isbn);
                float price;
                cout << "Price: ";
                cin >> price;
                int numCopiesInStock;
                cout << "Number of copies in stock: ";
                cin >> numCopiesInStock;

                books[bookCount++] = new bookType(title, authors, numAuthors, publisher, isbn, price, numCopiesInStock);
            }
            else {
                cout << "Maximum number of books reached!" << endl;
            }
            break;
        case 2:
            cout << "\n===== ALL BOOKS =====\n";
            for (int i = 0; i < bookCount; i++) {
                cout << "Book " << i + 1 << ":\n";
                books[i] -> showBookInfo();
            }
            break;
        case 3:
            if (bookCount > 0) {
                cin.ignore(); // clear input buffer
                string searchTitle;
                cout << "Enter the title to search: ";
                getline(cin, searchTitle);
                for (int i = 0; i < bookCount; i++) {
                    books[i]->searchByTitle(searchTitle);
                }
            }
            else {
                cout << "No books available to search!" << endl;
            }
            break;
        case 4:
            if (bookCount > 0) {
                cin.ignore(); // clear input buffer
                string searchISBN;
                cout << "Enter the ISBN to search: ";
                getline(cin, searchISBN);
                for (int i = 0; i < bookCount; i++) {
                    books[i]->searchByISBN(searchISBN);
                }
            }
            else {
                cout << "No books available to search!" << endl;
            }
            break;
        case 5:
            if (bookCount > 0) {
                int bookIndex, newStock;
                cout << "Enter the index of the book to update stock: ";
                cin >> bookIndex;
                if (bookIndex >= 0 && bookIndex < bookCount) {
                    cout << "Enter the new stock: ";
                    cin >> newStock;
                    books[bookIndex]->updateStock(newStock);
                    cout << "Stock updated successfully!" << endl;
                }
                else {
                    cout << "Invalid book index!" << endl;
                }
            }
            else {
                cout << "No books available to update stock!" << endl;
            }
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    // Free memory allocated to book objects
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }

    return 0;
}
