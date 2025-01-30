#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  
    int id = stoi(argv[1]);
    string name = argv[2];
    int units = stoi(argv[3]);

    float bill, amountcharged, surcharged = 0;

    if (units <= 199) {
        bill = 16.29 * units;
        amountcharged = 16.29;
    } else if (units > 199 && units < 300) {
        bill = 20.10 * units;
        amountcharged = 20.10;
    } else if (units >= 300 && units < 500) {
        bill = 27.10 * units;
        amountcharged = 27.10;
    } else {
        bill = 35.90 * units;
        amountcharged = 35.90;
    }

    if (bill > 18000) {
        surcharged = bill * 0.15;
    }

    float netamount = bill + surcharged;

    cout << "Customer ID : " << id << endl;
    cout << "Customer Name : " << name << endl;
    cout << "Units Consumed : " << units << endl;
    cout << "Amount Charges Rs. " << amountcharged << " per unit: " << bill << endl;
    cout << "Surcharge Amount: " << surcharged << endl;
    cout << "Net Amount Paid by the Customer: " << netamount << endl;

}
