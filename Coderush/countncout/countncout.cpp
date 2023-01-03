//https://www.hackerrank.com/contests/coderush-coding-contest/challenges/count-and-cout

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,i,count;
    char st[100];
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>st;
        int l = strlen(st);
        count=0;
        for(int i=0; i<l; i++)
        {
            if(st[i] == 'A'||st[i] == 'D'||st[i] == 'P'||st[i] == 'O'||st[i] == 'Q'||st[i] == 'R')
                count += 1;
            else if(st[i] == 'B')
                count += 2;
        }
        cout<<count<<"\n";
    }
    return 0;
}