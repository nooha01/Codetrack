#include <iostream>

using namespace std;

struct Pair
{
    int min;
    int max;
};  

Pair getminmax(int arr[], int n)
{
    Pair minmax;
    int i;
    if(n==1)
    {
        minmax.min = minmax.max = arr[0];
        return minmax;
    }
    
    if(arr[0]>arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for(i=2;i<n;i++)
    {
        if(arr[i] > minmax.max)
            minmax.max = arr[i];
        else if(arr[i] < minmax.min)
            minmax.min = arr[i];
    }

    return minmax;
}


int main()
{
    int arr[] = {1,2,4,6,8,2,1,33};
    int n = sizeof(arr)/sizeof(arr[0]);

    Pair minmax = getminmax(arr,n);

    cout<<"minimum element is: "<<minmax.min<<endl;
    cout<<"maximum element is: "<<minmax.max<<endl;
}


// time complexity : O(n)
// space complexity : O(1)
// no of comparisons = Worst case: 1+2(n-2)
// best case: 1+n-2