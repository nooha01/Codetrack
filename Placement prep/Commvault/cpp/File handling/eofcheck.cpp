#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("output.txt");

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        cout << "Read: " << line << endl;
    }

    if (inFile.eof()) {
        cout << "End of file reached." << endl;
    } else {
        cerr << "Error reading file!" << endl;
    }

    inFile.close();

    return 0;
}
