#include <iostream>
int gcd(int, int);
int main()
{
    int m, n, ans;
    scanf("%d", &m);
    scanf("%d", &n);
    while (m != n)
    {
        if (m > n)
        {
            m = m - n;
        }
        else
        {
            n = n - m;
        }
    }
    printf("%d", m);
    return 0;
}