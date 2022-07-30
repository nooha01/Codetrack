#include<bits/stdc++.h>
using namespace std;

void cost()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cost=0;
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i;j<n;j++)
            if(a[j]<a[min])
                min=j;
        cost+=min-i+1;
        for(int j=0;j<(min-i+1)/2;j++)
        {
            int temp=a[i+j];
            a[i+j]=a[min-j];
            a[min-j]=temp;
        }
    }
    cout<<cost<<endl;
}

int main()
{
    int T;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cout << "Case #" << i << ": ";
        cost();
    }
}
