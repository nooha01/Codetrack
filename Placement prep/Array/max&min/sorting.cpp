#include <iostream>
#include <algorithm>

using namespace std;

struct Pair
{
    int min;
    int max;
};  

Pair getminmax(int arr[], int n)
{
    Pair minmax;
    sort(arr,arr+n);
    minmax.min = arr[0];
    minmax.max = arr[n-1];
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


// time complexity : O(nlogn)
// space complexity; O(1)
// no of comparisons = O(logn)