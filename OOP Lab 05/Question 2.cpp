#include<iostream>
#include<vector>
using namespace std;

class car {
private:
    string name;
    string id;
public:
    car() {}
    car(string name, string id) {
        this->name = name;
        this->id = id;
    }
    void display() {
        cout << "Car Name: " << name << endl;
        cout << "Car Id: " << id << endl;
    }
    ~car() {
        cout << "Car exists from Garage." << endl;
    }
};

class garage {
private:
    vector<car*> cars;
public:
    garage() {
        cout << "Garage Created." << endl;
    }
    ~garage() {
        cout << "Garage destroyed." << endl;
        for (int i = 0; i < cars.size(); i++) {
            delete cars[i];
        }
    }
    void addcar(car* c) {
        cars.push_back(c);
        cout << "Car added successfully." << endl;
    }
    void listcar() {
        for (int i = 0; i < cars.size(); i++) {
            cars[i]->display();
        }
    }
};

int main() {
    car* c1 = new car("Civic", "1234");
    car* c2 = new car("Bmw i7", "D-0001");

    garage G;
    G.addcar(c1);
    G.addcar(c2);
    G.listcar();

    return 0;
}
