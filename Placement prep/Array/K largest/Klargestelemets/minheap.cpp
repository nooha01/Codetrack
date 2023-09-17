// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

/*
Build a Min Heap MH of the first K elements (arr[0] to arr[K-1]) of the given array
For each element, after the Kth element (arr[K] to arr[N-1]), compare it with the root of MH
If the element is greater than the root then make it root and call heapify for MH 
Else ignore it
Finally, MH has the K largest elements, and the root of the MH is the Kth largest element
*/

#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap {
    int size;
    int* arr;

    public:
        MinHeap(int size, int input[]);
        void heapify(int i);
        void buildHeap();
};

MinHeap::MinHeap(int size, int input[])
{
    this->size = size;
    this->arr = input;
    buildHeap();
}

void MinHeap::heapify(int i)
{
    if(i>=size/2)
        return;
    int smallest;
    int left = 2*i+1;
    int right = 2*i+2;

    smallest = arr[left]<arr[i]?left:i;
    if(right<size)
        smallest = arr[right]<arr[smallest]?right:smallest;
    
    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        heapify(smallest);
    }
}

void MinHeap::buildHeap()
{
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void KLargest(int arr[], int size, int k)
{
    MinHeap* m = new MinHeap(k, arr);
    for(int i=k;i<size;i++)
    {
        if(arr[0]>arr[i])
            continue;
        else
        {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,22,3,8,16,2,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    KLargest(arr,n,k);
}