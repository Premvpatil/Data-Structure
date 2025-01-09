#include <iostream>
using namespace std;

const int MAX_SIZE = 5;  // Maximum size of the queue

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;  // Variable to track the number of elements in the queue

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == MAX_SIZE;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to enqueue (insert) an element into the circular queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
        } else {
            if (front == -1) {  // If the queue is empty
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;  // Circular increment
            arr[rear] = element;
            count++;  // Increase the count
            cout << "Enqueued " << element << " into the queue." << endl;
        }
    }

    // Function to dequeue (remove) an element from the circular queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << "Dequeued " << arr[front] << " from the queue." << endl;
            front = (front + 1) % MAX_SIZE;  // Circular increment
            count--;  // Decrease the count
            if (count == 0) {
                front = rear = -1;  // Reset to empty state
            }
        }
    }

    // Function to get the front element of the queue
    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is " << arr[front] << endl;
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            for (int j = 0; j < count; j++) {  // Traverse `count` elements
                cout << arr[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue queue;
    int choice, element;

    while (true) {
        cout << "\nChoose an operation:\n"
             << "1: Enqueue Element\n"
             << "2: Dequeue Element\n"
             << "3: Get Front Element\n"
             << "4: Display Queue\n"
             << "5: Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the element to enqueue: ";
            cin >> element;
            queue.enqueue(element);
        } else if (choice == 2) {
            queue.dequeue();
        } else if (choice == 3) {
            queue.getFront();
        } else if (choice == 4) {
            queue.display();
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
