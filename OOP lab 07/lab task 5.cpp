#include <iostream>
#include <string>
using namespace std;

// Base class
class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string id, string pub) 
        : title(t), publicationDate(pDate), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }
    virtual ~Media() {}
};

// Derived class: Book
class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string id, string pub, string a, string isbn, int pages)
        : Media(t, pDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

// Derived class: DVD
class DVD : public Media {
    string director;
    int duration;
    double rating;
public:
    DVD(string t, string pDate, string id, string pub, string d, int dur, double r)
        : Media(t, pDate, id, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << endl;
    }
};

// Derived class: CD
class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string id, string pub, string a, int tracks, string g)
        : Media(t, pDate, id, pub), artist(a), numberOfTracks(tracks), genre(g) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

// Function Overloading for searching
void searchMedia(string title) {
    cout << "Searching for media by title: " << title << endl;
}
void searchMedia(string author, bool isBook) {
    cout << "Searching for book by author: " << author << endl;
}
void searchMedia(int year) {
    cout << "Searching for media by publication year: " << year << endl;
}

int main() {
    Book b("C++ Primer", "2020", "B001", "Pearson", "Lippman", "123456", 970);
    DVD d("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD c("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop");
    
    b.displayInfo();
    cout << "\n";
    d.displayInfo();
    cout << "\n";
    c.displayInfo();
    
    cout << "\n";
    searchMedia("C++ Primer");
    searchMedia("Lippman", true);
    searchMedia(2010);
    
    return 0;
}
