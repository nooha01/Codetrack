#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int number, int n) {
    int sum = 0;
    int temp = number;
    
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }
    
    return (sum == number);
}

int main() {
    int number, n;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the number of digits (n): ";
    cin >> n;

    if (isArmstrong(number, n)) {
        cout << number << " is an Armstrong number for " << n << " digits." << endl;
    } else {
        cout << number << " is not an Armstrong number for " << n << " digits." << endl;
    }

    return 0;
}
