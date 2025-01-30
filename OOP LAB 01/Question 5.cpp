#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){
    string labels[6] = {
        "Movie Name :",
        "Number of tickets sold:",
        "Gross Amount:",
        "Percentage of Gross amount donated:",
        "Amount Donated:",
        "Net Sale:"
    };
    
    int maxLabelLength = labels[3].length();
    string movieName;
    cout << "Enter movie name: ";
    cin >> movieName;
    
    int adultTicketsSold;
    cout << "Enter the number of adult tickets sold: ";
    cin >> adultTicketsSold;
    
    int childTicketsSold;
    cout << "Enter the number of child tickets sold: ";
    cin >> childTicketsSold;
    
    float childTicketPrice, adultTicketPrice;
    cout << "Enter the child ticket price: ";
    cin >> childTicketPrice;
    
    cout << "Enter the adult ticket price: ";
    cin >> adultTicketPrice;
    
    float donationPercentage;
    cout << "Enter the percentage to be donated: ";
    cin >> donationPercentage;
    
    int totalTicketsSold = childTicketsSold + adultTicketsSold;
    float grossAmount = (childTicketsSold * childTicketPrice) + (adultTicketsSold * adultTicketPrice);
    float amountDonated = (donationPercentage * grossAmount) / 100;
    float netSale = grossAmount - amountDonated;
    
    system("cls");
    
    float results[6] = {
        0, totalTicketsSold, grossAmount, donationPercentage, amountDonated, netSale
    };
    
    for(int i = 0; i < 6; i++) {
        cout << labels[i];
        if(labels[i].length() < maxLabelLength) {
            for(int j = labels[i].length(); j < maxLabelLength; j++) {
                cout << ".";
            }
        }
        
        if(i == 0) {
            cout << movieName;
        } else {
            printf("%.2f", results[i]);
        }
        
        cout << endl;
    }
    
}
