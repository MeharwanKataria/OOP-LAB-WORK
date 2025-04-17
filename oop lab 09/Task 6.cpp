#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
	string type;
	float cost;

public:
	Vehicle(string t) : type(t), cost(0.0) {}

	string getType() const {
		return type;
	}

	float getCost() const {
		return cost;
	}

	virtual void assignPrice(float c) = 0;
};

class PaintedVehicle : public Vehicle {
private:
	string paint;

public:
	PaintedVehicle(string t, string clr) : Vehicle(t), paint(clr) {}

	void assignPrice(float c) override {
		cost = c;
	}

	void showInfo() const {
		cout << "Type: " << type << ", Color: " << paint << ", Cost: " << cost << endl;
	}
};

class Manufacturer : public Vehicle {
private:
	string brand;

public:
	Manufacturer(string t, string b) : Vehicle(t), brand(b) {}

	void assignPrice(float c) override {
		cost = c;
	}

	void showInfo() const {
		cout << "Type: " << type << ", Maker: " << brand << ", Cost: " << cost << endl;
	}
};

int main() {
	PaintedVehicle redCar("Wagon", "Red");
	redCar.assignPrice(20000);
	redCar.showInfo();

	Manufacturer brandedCar("Sedan", "PhantomMotors");
	brandedCar.assignPrice(30000);
	brandedCar.showInfo();

	return 0;
}
