#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    string status;
    string borrower;

    Book(string title, string author, string ISBN, string status) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->status = status;
        this->borrower = "";
    }

    void checkIn() {
        status = "checked in";
        borrower = "";
    }

    void checkOut(string borrower) {
        status = "checked out";
        this->borrower = borrower;
    }
};

class Library {
public:
    vector<Book> books;

    void addBook(Book book) {
        books.push_back(book);
    }

    void removeBook(string ISBN) {
        for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->ISBN == ISBN) {
                books.erase(it);
                break;
            }
        }
    }

    void findBookByISBN(string ISBN) {
        for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->ISBN == ISBN) {
                cout << "Book found: " << it->title << " by " << it->author << endl;
                return;
            }
        }
        cout << "Book not found" << endl;
    }

    void displayAllBooks() {
        for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            cout << "Title: " << it->title << ", Author: " << it->author << ", ISBN: " << it->ISBN << ", Status: " << it->status << ", Borrower: " << it->borrower << endl;
        }
    }

    void displayAvailableBooks() {
        for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->status == "checked in") {
                cout << "Title: " << it->title << ", Author: " << it->author << ", ISBN: " << it->ISBN << endl;
            }
        }
    }
};

int main() {
    Library library;

    int choice;
    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Find book by ISBN" << endl;
        cout << "4. Display all books" << endl;
        cout << "5. Display available books" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Book book("", "", "", "");
                cout << "Enter title: ";
                cin >> book.title;
                cout << "Enter author: ";
                cin >> book.author;
                cout << "Enter ISBN: ";
                cin >> book.ISBN;
                library.addBook(book);
                break;
            case 2:
                string ISBN;
                cout << "Enter ISBN: ";
                cin >> ISBN;
                library.removeBook(ISBN);
                break;
            case 3:
                string isbn;
                cout << "Enter ISBN: ";
                cin >> isbn;
                library.findBookByISBN(isbn);
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5:
                library.displayAvailableBooks();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

