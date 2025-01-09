#include <iostream>
using namespace std;

// Constants for the array size
const int MAX_SIZE = 10;

// Function to check if the array is empty
bool isEmpty(int size) {
    return size == 0;
}

// Function to check if the array is full
bool isFull(int size) {
    return size == MAX_SIZE;
}

// Simplified function to insert an element into the array
void insertElement(int arr[], int& size, int element) {
    if (size < MAX_SIZE) {
        arr[size++] = element;
        cout << "Inserted " << element << " into the array." << endl;
    } else {
        cout << "Array is full. Cannot insert element." << endl;
    }
}

// Simplified function to delete an element from the array
void deleteElement(int arr[], int& size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            break;
        }
    }
    if (i < size) { // Element found
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
        cout << "Deleted " << element << " from the array." << endl;
    } else {
        cout << "Element " << element << " not found in the array." << endl;
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    if (isEmpty(size)) {
        cout << "Array is empty." << endl;
    } else {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[MAX_SIZE]; // Static array
    int size = 0;      // Current size of the array
    int choice, element;

    while (true) {
        cout << "\nChoose an operation:\n"
             << "1: Check if Array is Empty\n"
             << "2: Check if Array is Full\n"
             << "3: Insert Element\n"
             << "4: Delete Element\n"
             << "5: Display Array\n"
             << "6: Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << (isEmpty(size) ? "Array is empty." : "Array is not empty.") << endl;
        } else if (choice == 2) {
            cout << (isFull(size) ? "Array is full." : "Array is not full.") << endl;
        } else if (choice == 3) {
            cout << "Enter the element to insert: ";
            cin >> element;
            insertElement(arr, size, element);
        } else if (choice == 4) {
            cout << "Enter the element to delete: ";
            cin >> element;
            deleteElement(arr, size, element);
        } else if (choice == 5) {
            displayArray(arr, size);
        } else if (choice == 6) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
