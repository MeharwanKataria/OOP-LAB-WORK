#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AirRoute {
private:
	string code;
	string from;
	string to;
	int totalSeats;
	int reservedSeats;

public:
	AirRoute(string routeCode, string origin, string destination, int seats)
		: code(routeCode), from(origin), to(destination), totalSeats(seats), reservedSeats(0) {}

	bool reserveSeat() {
		if (reservedSeats < totalSeats) {
			reservedSeats++;
			cout << "Reservation successful on flight " << code << "\n";
			return true;
		}
		cout << "No seats available on flight " << code << "\n";
		return false;
	}

	bool revokeSeat() {
		if (reservedSeats > 0) {
			reservedSeats--;
			cout << "Reservation canceled on flight " << code << "\n";
			return true;
		}
		cout << "No reservations to cancel on flight " << code << "\n";
		return false;
	}

	bool enhanceSeat() {
		if (reservedSeats > 0) {
			cout << "Seat upgraded for flight " << code << "\n";
			return true;
		}
		cout << "Upgrade not possible for flight " << code << "\n";
		return false;
	}

	int getTotalSeats() const {
		return totalSeats;
	}

	int getReservedCount() const {
		return reservedSeats;
	}
};

class Traveler {
private:
	string fullName;
	string identity;

public:
	Traveler(string userName, string userID)
		: fullName(userName), identity(userID) {}

	void attemptReservation(AirRoute& flight) {
		if (flight.reserveSeat()) {
			cout << fullName << " reserved a seat successfully.\n";
		} else {
			cout << fullName << " could not reserve a seat.\n";
		}
	}

	void attemptCancel(AirRoute& flight) {
		if (flight.revokeSeat()) {
			cout << fullName << " canceled their seat successfully.\n";
		} else {
			cout << fullName << " failed to cancel their seat.\n";
		}
	}

	void attemptUpgrade(AirRoute& flight) {
		if (flight.enhanceSeat()) {
			cout << fullName << " upgraded their seat successfully.\n";
		} else {
			cout << fullName << " couldn't upgrade the seat.\n";
		}
	}
};

int main() {
	AirRoute route1("FL-101", "Adis Ababa", "Antarctica", 10);
	AirRoute route2("FL-202", "Chicago", "Florence", 5);

	Traveler t1("Tayyar", "ID001");
	Traveler t2("Murghi", "ID002");

	t1.attemptReservation(route1);
	t1.attemptReservation(route1);
	t1.attemptReservation(route1);
	t2.attemptReservation(route1);
	t2.attemptCancel(route1);
	t2.attemptUpgrade(route1);

	Traveler t3("Charlie", "ID003");
	t3.attemptReservation(route2);

	return 0;
}
