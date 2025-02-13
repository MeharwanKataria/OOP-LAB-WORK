#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookname;
    string isbn;
    string authorname;
    string publisher;

public:
    Book(string bookname, string isbn, string authorname, string publisher) {
        this->bookname = bookname;
        this->isbn = isbn;
        this->authorname = authorname;
        this->publisher = publisher;
    }
    Book() {
		this->bookname = "";
		this->isbn = "";
		this->authorname = "";
		this->publisher = "";
	}

    string getBookName() {
        return bookname;
    }

    string getISBN() {
        return isbn;
    }

    string getAuthorName() {
        return authorname;
    }

    string getPublisher() {
        return publisher;
    }

    string getBookInfo() {
        return "Book Name: " + bookname + "\nISBN: " + isbn + "\nAuthor Name: " + authorname + 
               "\nPublisher: " + publisher;
    }
};

int main(int argc, char* argv[]) {

    Book books[5];

    for (int i = 0; i < 5; i++) {
        string bookname = argv[i * 4 + 1];
        string isbn = argv[i * 4 + 2];
        string authorname = argv[i * 4 + 3];
        string publisher = argv[i * 4 + 4];

        books[i] = Book(bookname, isbn, authorname, publisher);
    }

    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << (i + 1) << " Information:\n" << books[i].getBookInfo() << endl;
    }

    return 0;
}

