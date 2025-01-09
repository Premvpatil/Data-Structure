#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    // Loop through the entire array
    for (int i = 0; i < size - 1; i++) {
        // Compare adjacent elements
        for (int j = 0; j < size - i - 1; j++) {
            // If the element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    cout << "Original array: ";
    displayArray(arr, size);  // Display original array

    // Call bubbleSort to sort the array
    bubbleSort(arr, size);

    cout << "Sorted array: ";
    displayArray(arr, size);  // Display sorted array

    return 0;
}
