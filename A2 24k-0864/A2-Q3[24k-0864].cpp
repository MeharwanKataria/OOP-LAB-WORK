#include <iostream>
#include <string>
using namespace std;

class vehicle {
protected:
    static int TotalNumberOfDeliveries;
    int id;
    int weight;
    double speed;
public:
    friend vehicle* AIConflictResolution(int id, double PackageWeight, vehicle** differentVehicle);
    vehicle(int id, double speed, double weight) : id(id), speed(speed), weight(weight) {}

    virtual void calculateOptimalRoute() = 0;
    virtual double estimatedDeliveryTime(double distance) = 0;
    virtual void deliverPackage(string packageID) = 0;

    bool operator==(const vehicle& v) {
        return (this->speed == v.speed) && (this->weight == v.weight);
    }
};

int vehicle::TotalNumberOfDeliveries = 0;

class RamzanTimeShip : public vehicle {
public:
    RamzanTimeShip(int id) : vehicle(id, 99999, 10) {}

    void deliverPackage(string packageID) {
        cout << "RamzanTimeShip " << id << " verifying historical accuracy before delivering package " << packageID << ".\n";
    }

    double estimatedDeliveryTime(double distance) {
        return 0;
    }

    void calculateOptimalRoute() {
        cout << "RamzanTimeShip " << id << " ensuring historical consistency in route selection.\n";
    }
};

class RamzanDrone : public vehicle {
public:
    RamzanDrone(int id) : vehicle(id, 90, 3.1) {}

    void deliverPackage(string packageID) {
        cout << "RamzanDrone " << id << " delivering package " << packageID << " via aerial route." << endl;
    }

    double estimatedDeliveryTime(double distance) {
        return distance / speed;
    }

    void calculateOptimalRoute() {
        cout << "RamzanDrone " << id << " optimizing aerial route for fast delivery." << endl;
    }
};

class RamzanHypePod : public vehicle {
public:
    RamzanHypePod(int id) : vehicle(id, 200, 50) {}

    void deliverPackage(string packageID) {
        cout << "RamzanHypePod " << id << " delivering package " << packageID << " through underground tunnel.\n";
    }

    double estimatedDeliveryTime(double distance) {
        return distance / speed;
    }

    void calculateOptimalRoute() {
        cout << "RamzanHypePod " << id << " optimizing underground tunnel network.\n";
    }
};

vehicle* AIConflictResolution(int id, double PackageWeight, vehicle** differentVehicle) {
    // Select the first vehicle that can carry the weight
    for (int i = 0; i < 3; i++) {
        if (PackageWeight <= differentVehicle[i]->weight) {
            return differentVehicle[i];
        }
    }
    return nullptr; // In case none can carry the weight
}

vehicle* AiDecision(string route, int id, double PackageWeight, vehicle** differentVehicle) {
    vehicle* v;
    if (route == "Aerial")
        v = differentVehicle[2];
    else if (route == "historical consistency")
        v = differentVehicle[0];
    else if (route == "tunnel network")
        v = differentVehicle[1];
    else
        v = AIConflictResolution(id, PackageWeight, differentVehicle);

    return v;
}

void command(string action, vehicle* vehicle, string packageID) {
    if (action == "Deliver") {
        vehicle->deliverPackage(packageID);
    }
}

void command(string action, vehicle* vehicle, string packageID, string urgencyLevel) {
    if (action == "Deliver") {
        if (urgencyLevel == "urgent") {
            cout << "Urgent package! Prioritizing fast delivery." << endl;
        }
        vehicle->deliverPackage(packageID);
    }
}

int main() {
    RamzanDrone rd(1001);
    RamzanHypePod rh(1002);
    RamzanTimeShip rts(1003);

    vehicle* v[3];
    v[0] = &rts; // historical
    v[1] = &rh;  // tunnel
    v[2] = &rd;  // aerial

    vehicle* v1 = AiDecision("Aerial", 1001, 2, v);
    vehicle* v2 = AiDecision("Sea", 1002, 30, v);

    command("Deliver", v1, "P123");
    command("Deliver", v2, "X12Y", "urgent");

    cout << "\nVehicle 1:" << endl;
    cout << "Vehicle 1 speed for 100 meters: " << v1->estimatedDeliveryTime(100) << " seconds" << endl;
    v1->calculateOptimalRoute();

    cout << "\nVehicle 2:" << endl;
    cout << "Vehicle 2 speed for 100 meters: " << v2->estimatedDeliveryTime(100) << " seconds" << endl;
    v2->calculateOptimalRoute();

    return 0;
}

