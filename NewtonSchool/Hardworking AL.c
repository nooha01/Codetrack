/*
Problem Statement
-----------------
Al is given task to build a skyscraper of N floors. He can build 2**i (2 to the power i, where i can be any non-negative integer) floors in one day. Report the minimum number of days required to build the skyscraper.
*/

#include <bits/stdc++.h> 
using namespace std;
int main() 
{
    long long n;
	cin>>n;
	int i=0;
    while(n)
	{
       i+=n&1;
	   n=n>>1;
	}
	cout<<i;
	return 0;
}
