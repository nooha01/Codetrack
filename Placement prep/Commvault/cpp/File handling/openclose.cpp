#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile; // Create an output file stream object
    outFile.open("output.txt"); // Open a file named "output.txt" for writing

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Hello, File Handling in C++!" << endl;

    outFile.close(); // Close the file

    return 0;
}
