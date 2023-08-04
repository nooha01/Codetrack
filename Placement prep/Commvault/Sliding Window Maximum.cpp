// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include <iostream>
using namespace std;

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, k = 3;
    int max;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-k;i=i+3)
    {
        max=arr[i];
        for(int j=1;j<k;j++)
        {
            if (arr[i+j]>max)
            {
                max=arr[i+j];
            }
            cout<<max<<" ";
        }
    }
}