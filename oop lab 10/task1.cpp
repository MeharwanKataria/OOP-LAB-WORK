#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string str;
	string encryptedString;
	string decryptedString;
	char ch;

	cout << "Please enter the string you want to encrypt: ";
	getline(cin, str);

	// Encrypting the text
	for (int i = 0; i < str.size(); i++) {
		ch = str[i] + 1;
		encryptedString += ch;
	}

	ofstream outFile("encrypt.txt");
	outFile << encryptedString;
	outFile.close();

	ifstream inFile("encrypt.txt");
	string readStr;
	inFile >> readStr;
	inFile.close();

	// Decrypting the text
	for (int i = 0; i < readStr.size(); i++) {
		ch = readStr[i] - 1;
		decryptedString += ch;
	}

	cout << "Encrypted string: " << encryptedString << endl;
	cout << "Decrypted string: " << decryptedString << endl;

	return 0;
}