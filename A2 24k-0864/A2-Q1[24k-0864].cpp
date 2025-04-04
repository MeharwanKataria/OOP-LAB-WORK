#include <iostream>
#include <string>
using namespace std;

class Buss {
protected:
    string route[4][4] = {
        {"NMC Kalapul", "Nadra DHA phase 2", "Imtiaz Super Market", "Cantt"},
        {"Sea view", "gulshan iqbal", "Zainab Market", "Clifton"},
        {"Korangi", "Shahrae faisal", "Gizri", "P&T colony"},
        {"Do talwar", "Bridge view", "Punjab Colony", "Nazimabad"}
    };
    int routes = 4, stops = 4;

public:
    int get_routes() const { 
	return routes; }
    int get_stops() const { 
	return stops; }
    string get_route_stop(int i, int j) const { 
	return route[i][j]; }


    bool operator==(const Buss& other) const {
        if (routes != other.routes || stops != other.stops) return false;
        
        for (int i = 0; i < routes; i++) {
            for (int j = 0; j < stops; j++) {
                if (route[i][j] != other.route[i][j]) return false;
            }
        }
        return true;
    }
};

class FAST_Member {
protected:
    string name;
    string id;
    char attendance;
    int fee_status;

public:
    FAST_Member(string n = "", string i = "") 
        : name(n), id(i), attendance('A'), fee_status(0) {}

    virtual ~FAST_Member() {}

    string getname() const { return name; }
    string getid() const { return id; }
    char getattendance() const { return attendance; }
    int getfee_status() const { return fee_status; }

    virtual void tap_buss() {
        if (fee_status == 0) {
            cout << "Couldn't record attendance because Fee is pending" << endl;
            cout << "Attendance status: " << attendance << endl;
            return;
        }
        cout << endl << name << " tapped on bus" << endl;
        cout << "Attendance recorded successfully! | previous status: " << attendance;
        attendance = 'P';
        cout << " | Current status - " << attendance << endl;
    }

    virtual void pay_fee() = 0; // Pure virtual function

    // Operator overloading to compare members
    bool operator==(const FAST_Member& other) const {
        return (name == other.name && id == other.id);
    }
};

class Student : public FAST_Member {
    string roll;

public:
    // Constructor chaining
    Student() : FAST_Member(), roll("") {}
    Student(string n, string r) : FAST_Member(n, r), roll(r) {}

    string getroll() const { return roll; }

    void pay_fee() override {
        fee_status = 1;
        cout << "Semester fee paid successfully! " << name 
             << " (ID: " << id << ")" << endl;
    }
};

class Teacher : public FAST_Member {
    string emp_id;
    int months_paid;

public:
    Teacher(string n = "", string e = "") 
        : FAST_Member(n, e), emp_id(e), months_paid(0) {}

    void pay_fee() override {
        fee_status = 1;
        months_paid++;
        cout << "Monthly fee paid successfully! " << name 
             << " (Total months paid: " << months_paid << ")" << endl;
    }

    void tap_buss() override {
        if (fee_status == 0) {
            cout << name << " (Teacher) couldn't record attendance - fee pending" << endl;
            return;
        }
        FAST_Member::tap_buss();
    }
};

class Staff : public FAST_Member {
    string staff_id;
    bool is_contract;

public:
    Staff(string n = "", string s = "", bool contract = false)
        : FAST_Member(n, s), staff_id(s), is_contract(contract) {}

    void pay_fee() override {
        fee_status = 1;
        cout << "Transport fee paid successfully! " << name 
             << " (" << (is_contract ? "Contract" : "Permanent") << " staff)" << endl;
    }
};

class Transport {
protected:
    string pickup, dropoff;
    Buss NadeemT;
    FAST_Member& member;

public:
    Transport(FAST_Member& m) : member(m), pickup(""), dropoff("") {}

    string get_pickup() const { return pickup; }
    string get_dropoff() const { return dropoff; }

    virtual void register_transport() {
        if (member.getfee_status() != 1) {
            cout << member.getname() << ", you must pay fees first to register for transport." << endl;
            return;
        }

        display_routes();
        cout << "Enter number of route and place for pickup: ";
        int i, j;
        cin >> i >> j;
        
        if (cin.fail() || i > 4 || i < 1 || j < 1 || j > 4) {
            cout << "Invalid Route and Stop number entered" << endl;
            return;
        }
        
        pickup = NadeemT.get_route_stop(i - 1, j - 1);
        dropoff = "FAST";
        cout << endl << member.getname() << " registered for Transport from " 
             << pickup << " to " << dropoff << endl;
    }

    void display_routes() const {
        cout << endl << "==================================================================" << endl;
        cout << "Welcome to FAST Transport service registration " << member.getname() << "!" << endl;
        cout << "Transport Routes and Pickups are: " << endl;
        
        for (int i = 0; i < NadeemT.get_routes(); i++) {
            cout << endl << "Route " << i + 1 << " : " << endl;
            for (int j = 0; j < NadeemT.get_stops(); j++) {
                cout << j + 1 << ". " << NadeemT.get_route_stop(i, j) << endl;
            }
        }
        cout << endl << "==================================================================" << endl;
    }
};

class StudentTransport : public Transport {
public:
    StudentTransport(Student& s) : Transport(s) {}

    void register_transport() override {
        cout << "STUDENT TRANSPORT REGISTRATION" << endl;
        Transport::register_transport();
    }
};

class TeacherTransport : public Transport {
public:
    TeacherTransport(Teacher& t) : Transport(t) {}

    void register_transport() override {
        cout << "TEACHER TRANSPORT REGISTRATION" << endl;
        Transport::register_transport();
        cout << "Note: Teachers get priority seating at the front of the bus." << endl;
    }
};

int main() {
    
    FAST_Member* members[3];
    
    Student s("Mehrwan", "24K-0864");
    Teacher t("Tushal", "T-1001");
    Staff st("John Doe", "S-2002", true);
    
    members[0] = &s;
    members[1] = &t;
    members[2] = &st;

    for (int i = 0; i < 3; i++) {
        members[i]->pay_fee();
    }

   
    StudentTransport st_transport(s);
    TeacherTransport tt_transport(t);
    Transport staff_transport(st);

    st_transport.register_transport();
    tt_transport.register_transport();
    staff_transport.register_transport();

    Buss b1, b2;
    if (b1 == b2) {
        cout << "\nAll bus routes are identical" << endl;
    }

    Student s2("Ali", "24K-0001");
    if (s == s2) {
        cout << "Students are the same" << endl;
    } else {
        cout << "\nStudents are different" << endl;
    }
    s.tap_buss();
    t.tap_buss();
    st.tap_buss();

    return 0;
}