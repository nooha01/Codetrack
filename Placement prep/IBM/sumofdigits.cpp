#include <iostream>
using namespace std;

int getSum(int n)
{
    int sum;
    for (sum = 0; n > 0; sum += n % 10, n /= 10)
        ;
    return sum;
}

int main()
{
    int n = 687;
    cout << getSum(n);
    return 0;
}