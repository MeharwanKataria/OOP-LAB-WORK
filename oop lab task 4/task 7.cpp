#include<iostream>
#include<cstring>
using namespace std;
class book{
	private:
		string author;
		string title;
		double price;
		string publisher;
		int stockposition;
	public:
		book(string author,string title,double price, string publisher,int stockposition){
			this->author=author;
			this->title=title;
			this->price=price;
			this->publisher=publisher;
			this->stockposition=stockposition;
		}
		string getauthor() { 
			return author;
		}
		string gettitle(){
			return title;
		}
		double getprice(){
			return price;
		}
		string getpublisher(){
			return publisher;
		}
		int getstockposition(){
			return stockposition;
		}
		void display()  {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stockposition<< endl;
        cout<<endl;
    }
		void search(string tit,string author){
			int copies;
				display();
				cout<<"Enter the amount of copies you want"<<endl;
				cin>>copies;
				if(copies>stockposition) cout<<"Required copies are not in stock."<<endl;
				else{
					cout<<"Total price of Copies: "<<copies*price;
					stockposition=stockposition-copies;
				}
	}
};
int main(int argc, char* argv[]){
 book books[] = {
        book("Faiz Ahmed Faiz", "The Pilgrim of Beauty", 1500, "Pakistani Publishers", 12),
        book("Ahmed Ali", "Twilight in Delhi", 1800, "Oxford University Press", 7),
        book("Ismat Chughtai", "The Heart Breaks", 1375, "Ferozsons", 5),
        book("Bapsi Sidhwa", "The Ice-Candy-Man", 2000, "Pakistani Press", 8),
        book("Intizar Hussain", "Basti", 2200, "Sang-e-Meel Publications", 4)
    };
    cout<<"Book inventory: "<<endl;
    int numbooks=sizeof(books)/sizeof(books[0]);
    for (int i = 0; i < numbooks; i++) {
    	cout<<"BOOK"<<i+1<<endl;
        books[i].display();
    }
    string title, author;
    cout << "\nEnter book title you are looking for: ";
    getline(cin, title);
    cout << "Enter author of the book: ";
    getline(cin, author);
    bool found = false;
    for (int i = 0; i < numbooks; i++) {
        if (books[i].gettitle() == title && books[i].getauthor() == author) {
            books[i].search(title, author);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Sorry, the book is not available." << endl;
    }

}
