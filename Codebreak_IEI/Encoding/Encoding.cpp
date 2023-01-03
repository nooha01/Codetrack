#include <bits/stdc++.h>
using namespace std;
    
void decode(int n, int k, string s)
{
    string msg;
    bool x = 0;
    for(int i = 0; i < n;i++)
    {
        if(i>=k)
        {
            x^= msg[i-k]-'0';
        }
        msg.push_back('0'+((s[i]-'0')^x));
        x^= msg.back()-'0';
    }
    cout<<msg;
}
    
int main()
{
    int n,k;
    string s;
    cin >>n>>k>>s;
    decode(n,k,s);
    return 0;
}