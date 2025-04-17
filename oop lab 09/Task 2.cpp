#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <set>

using namespace std;

class LogSystem {
private:
    vector<string> entries;
    const size_t MAX_ENTRIES = 10;
    const set<string> allowedModules = {"ArrivalNotice", "OutsideNoise", "IncidentReport", "BackendService"};

    void storeLog(const string& level, const string& source, const string& content) {
        if (entries.size() >= MAX_ENTRIES) {
            entries.erase(entries.begin());
        }

        if (content.empty() || source.empty()) {
            cout << "[LogSystem] Rejected empty log content/source.\n";
            return;
        }

        if (allowedModules.find(source) == allowedModules.end()) {
            cout << "[LogSystem] Module '" << source << "' is not authorized to log.\n";
            return;
        }

        string timestamp = "[2025-04-18 12:00:00] ";
        string formattedLog = timestamp + "[" + level + "] [" + source + "] " + content;
        entries.push_back(formattedLog);
    }

public:
    void info(const string& source, const string& message) {
        if (message.length() > 200) {
            cout << "[INFO] Message too long, not logged.\n";
            return;
        }
        storeLog("INFO", source, message);
    }

    void warn(const string& source, const string& message) {
        if (message.find("error") != string::npos) {
            cout << "[WARNING] Suspected error in warning message. Log as error instead.\n";
            storeLog("ERROR", source, message);
            return;
        }
        storeLog("WARNING", source, message);
    }

    void error(const string& source, const string& message) {
        storeLog("ERROR", source, message);
    }

    friend class SecurityAudit;
};

class SecurityAudit {
private:
    const string auditorID;
    const string auditorPass;
    const string validAccessCode = "X-AUD-ACCESS-001";

    bool verify(const string& inputID, const string& inputPass, const string& code) const {
        return inputID == auditorID && inputPass == auditorPass && code == validAccessCode;
    }

public:
    SecurityAudit(const string& id, const string& pass)
        : auditorID(id), auditorPass(pass) {}

    vector<string> accessLogs(const LogSystem& logSys, const string& inputID, const string& inputPass, const string& code) {
        if (verify(inputID, inputPass, code)) {
            return logSys.entries;
        } else {
            cout << "[Audit] Access Denied: Invalid credentials or code.\n";
            return {};
        }
    }
};

int main() {
    LogSystem systemLogger;

    systemLogger.info("ArrivalNotice", "THE KING HAS ENTERED THE BUILDING");
    systemLogger.warn("OutsideNoise", "Someone getting too bold out here...");
    systemLogger.error("IncidentReport", "Dad... I may have crashed the LC500 into a Mehran. He is now yelling in Urdu. Please come quick.");

    systemLogger.info("SecretOps", "This should not be logged.");
    systemLogger.warn("BackendService", "");

    for (int i = 4; i <= 6; ++i) {
        systemLogger.info("BackendService", "System check log #" + to_string(i));
    }

    SecurityAudit auditTeam("root", "toor");

    vector<string> retrievedLogs = auditTeam.accessLogs(systemLogger, "root", "toor", "X-AUD-ACCESS-001");

    cout << "\n=== Audit Log Review (" << retrievedLogs.size() << ") ===\n";
    for (const auto& entry : retrievedLogs) {
        cout << entry << "\n";
    }

    auditTeam.accessLogs(systemLogger, "root", "toor", "wrong-code");

    return 0;
}
