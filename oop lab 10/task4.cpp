#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int currentLine = 0;
	int logIndex = 1;
	ofstream outputFile("Output1.txt");

	if (!outputFile) {
		cout << "Error: Could not create initial log file." << endl;
		return 1;
	}

	string input;
	cout << "Start typing (enter END to finish):" << endl;

	while (true) {
		getline(cin, input);

		if (input == "END") {
			break;
		}

		outputFile << input << "\n";
		currentLine++;

		if (currentLine == 10) {
			outputFile.close();
			currentLine = 0;
			logIndex++;

			string nextFile = "Output" + to_string(logIndex) + ".txt";
			outputFile.open(nextFile);

			if (!outputFile) {
				cout << "Error: Could not create " << nextFile << endl;
				return 1;
			}
		}
	}

	outputFile.close();
	cout << "All input recorded successfully in " << logIndex << " file(s)." << endl;

	return 0;
}
