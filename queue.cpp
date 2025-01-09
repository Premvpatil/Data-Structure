#include <iostream>
using namespace std;

const int MAX_SIZE = 5;  // Maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
        } else {
            if (front == -1) {  // If the queue is empty
                front = 0;
            }
            rear++;
            arr[rear] = element;
            cout << "Enqueued " << element << " into the queue." << endl;
        }
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << "Dequeued " << arr[front] << " from the queue." << endl;
            front++;
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
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
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
