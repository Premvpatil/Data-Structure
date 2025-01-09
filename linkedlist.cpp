#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if the linked list is empty
bool isEmpty(Node* head) {
    return head == nullptr;
}

void insertElement(Node*& head, int element) {
    Node* newNode = new Node{element, head};
    head = newNode;
    cout << "Inserted " << element << " at the head of the list." << endl;
}


void deleteElement(Node*& head, int element) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // If the element to delete is at the head
    if (head->data == element) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << element << " from the list." << endl;
        return;
    }

}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
    } else {
        cout << "List: ";
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

int main() {
    Node* head = nullptr;
    int choice, element;

    while (true) {
        cout << "\n1: Check if List is Empty\n2: Insert Element\n3: Delete Element\n4: Display List\n5: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << (isEmpty(head) ? "List is empty." : "List is not empty.") << endl;
        } else if (choice == 2) {
            cout << "Enter element to insert: ";
            cin >> element;
            insertElement(head, element);
        } else if (choice == 3) {
            cout << "Enter element to delete: ";
            cin >> element;
            deleteElement(head, element);
        } else if (choice == 4) {
            displayList(head);
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
