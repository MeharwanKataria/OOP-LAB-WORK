#include <iostream>
#include <vector>
using namespace std;

struct menuitem {
    string name;
    string type;
    double price;
};

class coffee {
private:
    string name;
    vector<menuitem> menu;
    vector<string> orders;

public:
    coffee(string name, vector<menuitem> menu) {
        this->name = name;
        this->menu = menu;
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orders.size() == 0) {
            return "All orders have been fulfilled";
        }
        string fulfilledItem = orders[0];
        orders.erase(orders.begin());
        return "The " + fulfilledItem + " is ready";
    }

    vector<string> listorder() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orders.size(); i++) {
            for (int j = 0; j < menu.size(); j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items available";
        menuitem cheapest = menu[0];
        for (int i = 1; i < menu.size(); i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].type == "drink") {
                drinks.push_back(menu[i].name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].type == "food") {
                food.push_back(menu[i].name);
            }
        }
        return food;
    }
};

int main() {
    vector<menuitem> menu = {
        {"Espresso", "drink", 350.0},
        {"Latte", "drink", 450.0},
        {"Cappuccino", "drink", 500.0},
        {"Sandwich", "food", 750.0},
        {"Cake", "food", 600.0}
    };

    coffee myCoffeeShop("Pakistani Café", menu);

    cout << myCoffeeShop.addOrder("Espresso") << endl;
    cout << myCoffeeShop.addOrder("Cake") << endl;
    cout << myCoffeeShop.addOrder("Tea") << endl;

    vector<string> orders = myCoffeeShop.listorder();
    cout << "Current Orders: ";
    for (string order : orders) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total Due Amount: PKR " << myCoffeeShop.dueAmount() << endl;

    cout << myCoffeeShop.fulfillOrder() << endl;
    cout << myCoffeeShop.fulfillOrder() << endl;
    cout << myCoffeeShop.fulfillOrder() << endl;

    cout << "Cheapest Item: " << myCoffeeShop.cheapestItem() << endl;

    vector<string> drinks = myCoffeeShop.drinksOnly();
    cout << "Drinks: ";
   for (int i = 0; i < drinks.size(); i++) {
    cout << drinks[i] << " ";
	}
	cout << endl;

    vector<string> food = myCoffeeShop.foodOnly();
    cout << "Food: ";
   for (int i = 0; i < food.size(); i++) {
    cout << food[i] << " ";}
	cout << endl;


    return 0;
}

