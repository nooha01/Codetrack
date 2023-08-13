#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("output.txt");
    
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Hello, File Handling in C++!" << endl;
    outFile << 42 << " " << 3.14 << endl;

    outFile.close();

    // Reading from file
    ifstream inFile("output.txt");

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int intValue;
    double doubleValue;

    getline(inFile, line);
    inFile >> intValue >> doubleValue;

    cout << "Read: " << line << endl;
    cout << "Int: " << intValue << ", Double: " << doubleValue << endl;

    inFile.close();

    return 0;
}
