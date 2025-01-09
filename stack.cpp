#include <iostream>
using namespace std;

const int MAX_SIZE = 10;  // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;  // Initialize the stack as empty
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << element << endl;
        } else {
            arr[++top] = element;
            cout << "Pushed " << element << " onto the stack." << endl;
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            cout << "Popped " << arr[top--] << " from the stack." << endl;
        }
    }

    // Function to peek at the top element of the stack
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is " << arr[top] << endl;
        }
    }

    // Function to display the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, element;

    while (true) {
        cout << "\nChoose an operation:\n"
             << "1: Push Element\n"
             << "2: Pop Element\n"
             << "3: Peek\n"
             << "4: Display Stack\n"
             << "5: Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the element to push: ";
            cin >> element;
            stack.push(element);
        } else if (choice == 2) {
            stack.pop();
        } else if (choice == 3) {
            stack.peek();
        } else if (choice == 4) {
            stack.display();
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
