#include <iostream>
using namespace std;

// Node structure for a circular linked list
struct Node {
    int data;
    Node* next;
};

// Class for Circular Linked List
class CircularLinkedList {
private:
    Node* head;  // Pointer to the first node in the list

public:
    CircularLinkedList() {
        head = nullptr;  // Initialize the list as empty
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to insert a node at the end of the circular linked list
    void insert(int element) {
        Node* newNode = new Node();
        newNode->data = element;

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;  // Pointing to itself to make the list circular
        } else {
            Node* temp = head;
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Make the list circular
        }
        cout << "Inserted " << element << " into the list." << endl;
    }

    // Function to delete a node with a specific value
    void deleteNode(int element) {
        if (isEmpty()) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;

        // Case 1: The node to delete is the only node in the list
        if (head->data == element && head->next == head) {
            delete head;
            head = nullptr;
            cout << "Deleted " << element << " from the list." << endl;
            return;
        }

        // Case 2: The node to delete is the head node
        if (head->data == element) {
            while (temp->next != head) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = head->next;  // Last node should point to the new head
            Node* toDelete = head;
            head = head->next;  // Move head to the next node
            delete toDelete;
            cout << "Deleted " << element << " from the list." << endl;
            return;
        }

        // Case 3: The node to delete is not the head node
        Node* prev = nullptr;
        while (temp->next != head && temp->data != element) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data == element) {
            prev->next = temp->next;  // Bypass the node to delete
            delete temp;
            cout << "Deleted " << element << " from the list." << endl;
        } else {
            cout << "Element " << element << " not found in the list." << endl;
        }
    }

    // Function to display the elements of the circular linked list
    void display() {
        if (isEmpty()) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);  // Continue until we get back to the head
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, element;

    while (true) {
        cout << "\nChoose an operation:\n"
             << "1: Insert Element\n"
             << "2: Delete Element\n"
             << "3: Display List\n"
             << "4: Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the element to insert: ";
            cin >> element;
            list.insert(element);
        } else if (choice == 2) {
            cout << "Enter the element to delete: ";
            cin >> element;
            list.deleteNode(element);
        } else if (choice == 3) {
            list.display();
        } else if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
