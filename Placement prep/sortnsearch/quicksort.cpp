#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // choose the last element as the pivot
    int i = low - 1; // index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1; // return the index of the pivot element
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Unsorted array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
