#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n-1; i++) {
        // Assume the current index is the minimum
        minIndex = i;

        // Find the minimum element in the unsorted part
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Unsorted array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
