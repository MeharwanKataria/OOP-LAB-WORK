#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MedicalAccess;
class FinanceAccess;

class PatientProfile {
private:
    string fullName;
    string patientID;
    string birthDate;

    vector<string> healthHistory;
    vector<string> ongoingTreatments;
    vector<string> paymentRecords;

public:
    PatientProfile(string fullName, string patientID, string birthDate)
        : fullName(fullName), patientID(patientID), birthDate(birthDate) {}

    string getBasicInfo() const {
        return "Full Name: " + fullName + ", ID: " + patientID;
    }

    string getHealthInfo() const {
        return "Medical History: " + combine(healthHistory) +
               ", Current Treatments: " + combine(ongoingTreatments);
    }

    void appendToHistory(const string& note) {
        healthHistory.push_back(note);
    }

    void prescribeTreatment(const string& treatment) {
        ongoingTreatments.push_back(treatment);
    }

    void recordPayment(const string& payment) {
        paymentRecords.push_back(payment);
    }

    string viewPayments() const {
        return combine(paymentRecords);
    }

private:
    static string combine(const vector<string>& items) {
        string output;
        for (const auto& entry : items) {
            output += entry + "; ";
        }
        return output;
    }

    friend class MedicalAccess;
    friend class FinanceAccess;
};

class MedicalAccess {
public:
    static void addMedicalNote(PatientProfile& profile, const string& note) {
        profile.appendToHistory(note);
    }

    static void assignTreatment(PatientProfile& profile, const string& treatment) {
        profile.prescribeTreatment(treatment);
    }

    static string fetchMedicalDetails(const PatientProfile& profile) {
        return profile.getHealthInfo();
    }
};

class FinanceAccess {
public:
    static void insertBill(PatientProfile& profile, const string& bill) {
        profile.recordPayment(bill);
    }

    static string fetchBillingData(const PatientProfile& profile) {
        return profile.viewPayments();
    }
};

class FrontDesk {
public:
    static void accessPublicInfo(PatientProfile& profile) {
        cout << "[FrontDesk] Viewing Public Details: " << profile.getBasicInfo() << endl;
    }
};

int main() {
    PatientProfile individual("Jane Smith", "A1023", "1988-06-12");

    FrontDesk::accessPublicInfo(individual);

    MedicalAccess::addMedicalNote(individual, "High Blood Pressure");
    MedicalAccess::assignTreatment(individual, "Prescribed beta-blockers");
    cout << "[Doctor] Medical Overview: " << MedicalAccess::fetchMedicalDetails(individual) << endl;

    FinanceAccess::insertBill(individual, "CT Scan - $350");
    cout << "[Billing Dept] Payment Records: " << FinanceAccess::fetchBillingData(individual) << endl;

    return 0;
}
