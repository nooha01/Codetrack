// https://www.hackerrank.com/contests/coderush-coding-contest/challenges/brother-trouble

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    float T,res,i,x,y,m,c;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>x>>y>>m>>c;
        res=m*x+c;
        if(res==y)
        {
            cout<<"ON THE LINE\n";
        }
        else
        {
            cout<<"NOT ON THE LINE\n";
        }
    }
    return 0;
}