#include<iostream>
#include<fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct User {
	string user_id, first_name, last_name, address, email;
};

struct Product {
	string product_id, product_name, description;
	int price;
};

struct Order {
	string order_id, user_id, product_id;
	int total_paid;
};

// FUNCTION MADE TO GET ALL THE USERS, PRODUCTS AND ORDERS FROM THE FILE INTO A VECTOR SO THAT WE CAN LATER ON SEACH THEM IN THE VECTOR
vector<Product> loadProducts(const string& filename){
	vector<Product> products;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		stringstream inp(line);
		Product p;
		string price_str;
		getline(inp, p.product_id, ',');
		getline(inp, p.product_name, ',');
		getline(inp, p.description, ',');
		getline(inp, price_str, ',');
		p.price = stoi(price_str);
		products.push_back(p);
		}

	return products;
}

vector<User> loadUsers(const string& filename){
	vector<User> users;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		User u;
		getline(ss, u.user_id, ',');
		getline(ss, u.first_name, ',');
		getline(ss, u.last_name, ',');
		getline(ss, u.address, ',');
		getline(ss, u.email, ',');
		users.push_back(u);
		}

	return users;
}

vector<Order> loadOrders(const string& filename) {
	vector<Order> orders;
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		stringstream inp(line);
		Order o;
		string total_paid_str;
		getline(inp, o.order_id, ',');
		getline(inp, o.user_id, ',');
		getline(inp, o.product_id, ',');
		getline(inp, total_paid_str, ',');
		o.total_paid = stoi(total_paid_str);
		orders.push_back(o);
	}

	return orders;
}

int main(){

	vector<User> users = loadUsers("Users.txt");
	vector<Product> products = loadProducts("Products.txt");
	vector<Order> orders = loadOrders("Order.txt");

	string linus_id = "";
	for(const auto& user: users){
		if(user.first_name == "Linus"){
			linus_id = user.first_name;
			break;
		}
	}

	if(linus_id.empty()){
		cout << "Linus Not Found!" <<endl;
		return 1;
	}

	vector<string> linus_products;
	for (const auto& o : orders) {
		if (o.user_id == linus_id) {
			linus_products.push_back(o.product_id);
		}
	}


	for(const auto& prods: linus_products){
		cout << prods << endl;
	}
	
	return 0;
}