#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n,t,val=0;
    cin>>n>>t;
    int sum;
    array <int,100000> arr1;
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int i=0;i<n;i++)
    {
        sum=arr1[i];
        if (sum<=t)
        val++;
        else
        continue;
        for (int j=i+1;j<n;j++)
        {
            sum+=arr1[j];
            if(sum>t)
            break;
            else
            val++;
        }
    }
    cout<<(float)val/n/(n+1)*2;
    return 0;
}