// https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/

// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include <iostream>
#include <algorithm>
using namespace std;

void KLargest(int arr[], int n, int k)
{
    // sort(arr, arr + n, greater<int>()); // descending order
    sort(arr, arr + n);

    cout << arr[k-1] << endl;
}

int main()
{
     int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    KLargest(arr, n, k);
}

// Time Complexity: O(sN * K)