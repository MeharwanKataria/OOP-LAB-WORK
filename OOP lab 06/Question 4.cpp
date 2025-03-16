#include <iostream>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string genre) : genre(genre) {}

    virtual void displayDetails() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string title, string author) : Books("Novel"), title(title), author(author) {}

    void displayDetails() override {
    	cout<<"\nNovels: "<<endl;
        cout<<"Genre: " << genre << endl;
        cout<<"Title: " << title << endl;
        cout<<"Author: " << author << endl;
        
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string title, string author) : Books("Mystery"), title(title), author(author) {}

    void displayDetails() override {
    	cout<<"\nMystery Books:"<<endl;
        cout<<"Genre: " << genre << endl;
        cout<<"Title: " << title << endl;
        cout<<"Author: " << author << endl;
    
    }
};

int main() {
    Novel book1("Pride and Prejudice", "Jane Austen");
    Mystery book2("Sherlock Holmes", "Arthur Conan Doyle");

    cout << "School Library Collection" << endl;
    book1.displayDetails();
    book2.displayDetails();

    return 0;
}

