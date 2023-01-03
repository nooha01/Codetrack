#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int boy[n], girl[n], pair[n], val=n-1;
        for(i = 0; i < n; i++)
            cin >> boy[i];
        for(i = 0; i < n; i++)
            cin >> girl[i];
        sort(boy, boy+n);
        sort(girl, girl+n);
        for(i = 0; i < n; i++)
            pair[i] = boy[(val)--] + girl[i];
        sort(pair, pair+n);
        cout << pair[n-1] << endl;
    }
    return 0;
}
