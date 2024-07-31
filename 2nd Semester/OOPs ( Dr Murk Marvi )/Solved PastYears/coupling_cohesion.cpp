/*
    Coupling: Refers to the degree of direct knowledge that one class has of another. In a highly
coupled system, changes in one class will likely require changes in other classes. The goal is to achieve
low (or loose) coupling.
    Cohesion: Refers to how closely related and focused the responsibilities of a single module/class
are. High cohesion means the class does a well-defined job and is easy to maintain.

    High Cohesion:
1.  Each class has a well-defined purpose:
2.  Book class manages book details and borrowing status.
3.  User class manages user details and borrowed books.
4.  Library class manages the collection of books and users, and handles borrowing and returning books.
5.  Each class has methods that are closely related to its purpose, which makes the code easy to understand and maintain.

    Low Coupling:
1.  The Library class interacts with the Book and User classes through well-defined interfaces (methods). The internal implementation details of Book and User are hidden from Library.
2.  Changes in the Book or User class will have minimal impact on the Library class, as long as the interface remains consistent.

    Justification for Good Design Pattern
This design adheres to principles of good design by promoting high cohesion and low coupling:

    Encapsulation: Each class manages its own state and behavior, reducing complexity.
    Single Responsibility Principle: Each class has a single responsibility, making the system easier to 
understand and maintain.
    Modularity: The system is divided into distinct modules (classes), which can be developed, tested,
and maintained independently.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book {
private:
    std::string title;
    std::string author;
    bool isBorrowed;

public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author), isBorrowed(false) {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    bool getIsBorrowed() const {
        return isBorrowed;
    }

    void borrowBook() {
        isBorrowed = true;
    }

    void returnBook() {
        isBorrowed = false;
    }
};

class User {
private:
    std::string name;
    std::vector<std::string> borrowedBooks;

public:
    User(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

    void borrowBook(const std::string& bookTitle) {
        borrowedBooks.push_back(bookTitle);
    }

    void returnBook(const std::string& bookTitle) {
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookTitle), borrowedBooks.end());
    }

    void displayBorrowedBooks() const {
        std::cout << "Books borrowed by " << name << ":\n";
        for (const auto& book : borrowedBooks) {
            std::cout << "- " << book << "\n";
        }
    }
};

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addUser(const User& user) {
        users.push_back(user);
    }

    void borrowBook(const std::string& userName, const std::string& bookTitle) {
        auto userIt = std::find_if(users.begin(), users.end(), [&userName](const User& user) {
            return user.getName() == userName;
        });

        auto bookIt = std::find_if(books.begin(), books.end(), [&bookTitle](const Book& book) {
            return book.getTitle() == bookTitle && !book.getIsBorrowed();
        });

        if (userIt != users.end() && bookIt != books.end()) {
            userIt->borrowBook(bookTitle);
            bookIt->borrowBook();
            std::cout << userName << " borrowed " << bookTitle << "\n";
        } else {
            std::cout << "Book is not available or user not found\n";
        }
    }

    void returnBook(const std::string& userName, const std::string& bookTitle) {
        auto userIt = std::find_if(users.begin(), users.end(), [&userName](const User& user) {
            return user.getName() == userName;
        });

        auto bookIt = std::find_if(books.begin(), books.end(), [&bookTitle](const Book& book) {
            return book.getTitle() == bookTitle && book.getIsBorrowed();
        });

        if (userIt != users.end() && bookIt != books.end()) {
            userIt->returnBook(bookTitle);
            bookIt->returnBook();
            std::cout << userName << " returned " << bookTitle << "\n";
        } else {
            std::cout << "Book is not borrowed or user not found\n";
        }
    }

    void displayBooks() const {
        std::cout << "Library books:\n";
        for (const auto& book : books) {
            std::cout << book.getTitle() << " by " << book.getAuthor() << (book.getIsBorrowed() ? " (borrowed)\n" : "\n");
        }
    }

    void displayUsers() const {
        std::cout << "Library users:\n";
        for (const auto& user : users) {
            std::cout << user.getName() << "\n";
        }
    }
};

int main() {
    Library library;

    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    library.addUser(User("Alice"));
    library.addUser(User("Bob"));

    library.displayBooks();
    library.displayUsers();

    library.borrowBook("Alice", "1984");
    library.borrowBook("Bob", "To Kill a Mockingbird");

    library.displayBooks();

    library.returnBook("Alice", "1984");
    library.displayBooks();

    return 0;
}

