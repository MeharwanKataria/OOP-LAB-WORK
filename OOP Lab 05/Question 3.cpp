#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string isbn;
    string title;
    string author;
    bool isLoaned;

    Book(string isbn, string title, string author)
        : isbn(isbn), title(title), author(author), isLoaned(false) {}

    string getISBN() { return isbn; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    
    bool isAvailable() { return !isLoaned; }
    void loan() { isLoaned = true; }
    void returnBook() { isLoaned = false; }
};

class Catalog {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    Book* findBookByISBN(string isbn) {
        for (auto &book : books) {
            if (book.getISBN() == isbn) {
                return &book;
            }
        }
        return nullptr;
    }

    void removeBook(string isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                books.erase(it);
                return;
            }
        }
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;

public:
    Library(string name, string address) : name(name), address(address) {}

    void addBook(Book book) {
        catalog.addBook(book);
    }

    Book* findBookInCatalog(string isbn) {
        return catalog.findBookByISBN(isbn);
    }

    void removeBook(string isbn) {
        catalog.removeBook(isbn);
    }

    void loanBook(string isbn) {
        Book* book = findBookInCatalog(isbn);
        if (book != nullptr && book->isAvailable()) {
            book->loan();
            cout << "Book '" << book->getTitle() << "' loaned successfully!" << endl;
        } else if (book == nullptr) {
            cout << "Book not found!" << endl;
        } else {
            cout << "Book is already loaned out!" << endl;
        }
    }

    void returnBook(string isbn) {
        Book* book = findBookInCatalog(isbn);
        if (book != nullptr && !book->isAvailable()) {
            book->returnBook();
            cout << "Book '" << book->getTitle() << "' returned successfully!" << endl;
        } else if (book == nullptr) {
            cout << "Book not found!" << endl;
        } else {
            cout << "Book was not loaned out!" << endl;
        }
    }

    void displayLibraryInfo() {
        cout << "Library Name: " << name << "\nAddress: " << address << endl;
    }
};

int main() {
    Library library("PACC Library", "Near Cantt station");

    Book book1("fast1234-2", "C++ Programming", "John");
    Book book2("fast1234-1", "Data Structures", "Aly");

    library.addBook(book1);
    library.addBook(book2);

    library.displayLibraryInfo();

    string isbnToSearch = "fast1234-1";
    Book* foundBook = library.findBookInCatalog(isbnToSearch);
    if (foundBook) {
        cout << "Found Book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << endl;
    } else {
        cout << "Book not found!" << endl;
    }

    library.loanBook(isbnToSearch);

    foundBook = library.findBookInCatalog(isbnToSearch);
    if (foundBook) {
        cout << "Found Book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << endl;
    }

    library.loanBook(isbnToSearch);

    library.returnBook(isbnToSearch);

    foundBook = library.findBookInCatalog(isbnToSearch);
    if (foundBook) {
        cout << "Found Book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << endl;
    }

    library.returnBook(isbnToSearch);

    return 0;
}
