#include <iostream>
#include <string>

using namespace std;


class User {
private:
    string name;
    int age;
    string licenseType;
    string contactInfo;
    string userID;

public:
    User() : name(""), age(0), licenseType(""), contactInfo(""), userID("") {} // Default constructor
    User(string name, int age, string licenseType, string contactInfo, string userID) {
        this->name = name;
        this->age = age;
        this->licenseType = licenseType;
        this->contactInfo = contactInfo;
        this->userID = userID;
    }

    // Update user details
    void updateDetails() {
        cout << "Enter new name: "; cin >> name;
        cout << "Enter new age: "; cin >> age;
        cout << "Enter new license type (Learner/Intermediate/Full): "; cin >> licenseType;
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getLicenseType() { return licenseType; }
    string getContactInfo() { return contactInfo; }
    string getUserID() { return userID; }

    // Display user details
    void displayDetails() {
        cout << "User ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "License Type: " << licenseType << endl;
        cout << "Contact Info: " << contactInfo << endl;
    }
};

// Class to represent a Vehicle
class Vehicle {
private:
    string model;
    double rentalPrice;
    string requiredLicenseType;

public:
    Vehicle() : model(""), rentalPrice(0.0), requiredLicenseType("") {} // Default constructor
    Vehicle(string model, double rentalPrice, string requiredLicenseType) {
        this->model = model;
        this->rentalPrice = rentalPrice;
        this->requiredLicenseType = requiredLicenseType;
    }

    // Getters
    string getModel() { return model; }
    double getRentalPrice() { return rentalPrice; }
    string getRequiredLicenseType() { return requiredLicenseType; }

    // Display vehicle details
    void displayDetails() {
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalPrice << " per day" << endl;
        cout << "Required License Type: " << requiredLicenseType << endl;
    }
};


class RentalSystem {
private:
    User* users[10]; 
    int userCount;
    Vehicle* vehicles[10]; 
    int vehicleCount;

public:
    RentalSystem() : userCount(0), vehicleCount(0) {
        for (int i = 0; i < 10; i++) {
            users[i] = nullptr;
            vehicles[i] = nullptr;
        }
    }

    ~RentalSystem() {
      
        for (int i = 0; i < userCount; i++) {
            delete users[i];
        }
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
    }

    // Register a new user
    void registerUser() {
        if (userCount >= 10) {
            cout << "User limit reached. Cannot register more users.\n";
            return;
        }

        string name, licenseType, contactInfo, userID;
        int age;

        cout << "Enter name: "; cin >> name;
        cout << "Enter age: "; cin >> age;
        cout << "Enter license type (Learner/Intermediate/Full): "; cin >> licenseType;
        cout << "Enter contact info: "; cin >> contactInfo;
        cout << "Enter user ID: "; cin >> userID;

        users[userCount++] = new User(name, age, licenseType, contactInfo, userID);
        cout << "User registered successfully!\n";
    }

    void updateUserDetails(string userID) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUserID() == userID) {
                users[i]->updateDetails();
                cout << "User details updated successfully!\n";
                return;
            }
        }
        cout << "User not found.\n";
    }

    void addVehicle() {
        if (vehicleCount >= 10) {
            cout << "Vehicle limit reached. Cannot add more vehicles.\n";
            return;
        }

        string model, requiredLicenseType;
        double rentalPrice;

        cout << "Enter vehicle model: "; cin >> model;
        cout << "Enter rental price per day: "; cin >> rentalPrice;
        cout << "Enter required license type (Learner/Intermediate/Full): "; cin >> requiredLicenseType;

        vehicles[vehicleCount++] = new Vehicle(model, rentalPrice, requiredLicenseType);
        cout << "Vehicle added successfully!\n";
    }

    void displayVehicles() {
        if (vehicleCount == 0) {
            cout << "No vehicles available.\n";
            return;
        }

        cout << "===== Available Vehicles =====\n";
        for (int i = 0; i < vehicleCount; i++) {
            vehicles[i]->displayDetails();
            cout << "-------------------\n";
        }
    }


    void rentVehicle(string userID, string model) {
        User* user = nullptr;
        Vehicle* vehicle = nullptr;

    
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUserID() == userID) {
                user = users[i];
                break;
            }
        }

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getModel() == model) {
                vehicle = vehicles[i];
                break;
            }
        }

        if (user && vehicle) {
            if (user->getLicenseType() == vehicle->getRequiredLicenseType()) {
                cout << "Vehicle rented successfully!\n";
                cout << "User: " << user->getName() << endl;
                cout << "Vehicle: " << vehicle->getModel() << endl;
                cout << "Rental Price: $" << vehicle->getRentalPrice() << " per day\n";
            } else {
                cout << "You are not eligible to rent this vehicle. Required license: " << vehicle->getRequiredLicenseType() << endl;
            }
        } else {
            cout << "User or vehicle not found.\n";
        }
    }
};

int main() {
    RentalSystem system;
    int choice;
    string userID, model;

    do {
        cout << "\n===== Vehicle Rental System =====\n";
        cout << "1. Register User\n";
        cout << "2. Update User Details\n";
        cout << "3. Add Vehicle\n";
        cout << "4. Display Available Vehicles\n";
        cout << "5. Rent Vehicle\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.registerUser();
                break;
            case 2:
                cout << "Enter user ID: "; cin >> userID;
                system.updateUserDetails(userID);
                break;
            case 3:
                system.addVehicle();
                break;
            case 4:
                system.displayVehicles();
                break;
            case 5:
                cout << "Enter user ID: "; cin >> userID;
                cout << "Enter vehicle model: "; cin >> model;
                system.rentVehicle(userID, model);
                break;
            case 6:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
