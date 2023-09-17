// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include <iostream>
#include <algorithm>
using namespace std;

void KLargest(int arr[], int n, int k)
{
    sort(arr,arr+n, greater<int>());
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[] = {1,22,3,8,16,2,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    KLargest(arr,n,k);
}

// Time Complexity: O(N * K)