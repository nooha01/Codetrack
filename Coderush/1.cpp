// https://www.hackerrank.com/contests/coderush-coding-contest/challenges/up-for-a-retest

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,i,m;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>m;
        if(m>=12)
            cout<<"PARTY ALL NIGHT!\n";
        else
             cout<<"STUDY ALL NIGHT!\n";
    }
    return 0;
}
