/*
Algorithm:

Pair MaxMin(array, array_size)
    if array_size = 1
        return element as both max and min
    else if arry_size = 2
        one comparison to determine max and min
         return that pair
    else
        recur for max and min of left half
        recur for max and min of right half
        one comparison determines true max of the two candidates
        one comparison determines true min of the two candidates
        return the pair of max and min
*/

#include <iostream>

using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair getminmax(int arr[], int low, int high)
{
    Pair minmax, left, right;
    int mid;
    if (low == high)
    {
        minmax.min = minmax.max = arr[0];
        return minmax;
    }
    else if (high == (low + 1))
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }

        return minmax;
    }

    mid = (low + high) / 2;
    left = getminmax(arr, low, mid);
    right = getminmax(arr, mid + 1, high);

    minmax.min = (left.min < right.min) ? left.min : right.min;
    minmax.max = (left.max > right.max) ? left.max : right.max;

    return minmax;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 8, 2, 1, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair minmax = getminmax(arr, 0, n - 1);

    cout << "minimum element is: " << minmax.min << endl;
    cout << "maximum element is: " << minmax.max << endl;
}

// time complexity : O(n)
// space complexity : O(logn)
// no of comparisons = 3n/2 -2

/*
Algorithmic Paradigm: Divide and Conquer 

T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2
T(2) = 1
T(1) = 0

If n is a power of 2, then we can write T(n) as: 

T(n) = 2T(n/2) + 2

After solving the above recursion, we get 

T(n)  = 3n/2 -2
*/