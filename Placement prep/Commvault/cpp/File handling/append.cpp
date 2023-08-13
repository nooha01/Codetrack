#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("output.txt", ios::app);

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Appending more data." << endl;

    outFile.close();

    return 0;
}
