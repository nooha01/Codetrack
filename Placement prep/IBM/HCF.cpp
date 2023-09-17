#include <iostream>
using namespace std;

// Function to calculate HCF using the Euclidean algorithm
int calculateHCF(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    int hcf = calculateHCF(num1, num2);

    cout << "The HCF of " << num1 << " and " << num2 << " is: " << hcf << endl;

    return 0;
}
