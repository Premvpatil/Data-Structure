#include<iostream>
using namespace std;

#define ARRAY_SIZE 10

int binaryTree[ARRAY_SIZE]; 

void initTree() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        binaryTree[i] = -1;  // Initialize all nodes to -1 (indicating empty spots)
    }
}

// Function to insert a node in the binary search tree
void insertNode(int key) {
    int i = 0;
    while (i < ARRAY_SIZE) {
        if (binaryTree[i] == -1) {  
            binaryTree[i] = key;  // Insert the node
            return;
        } else if (key < binaryTree[i]) {  // left child
            i = 2 * i + 1;
        } else {  //  right child
            i = 2 * i + 2;
        }
    }
}

// Function to print the tree
//void printTree() {
//    cout << "Tree representation in array form: ";
//    for (int i = 0; i < ARRAY_SIZE; i++) {
//        if (binaryTree[i] != -1) {
//            cout << binaryTree[i] << " ";
//        }
//    }
//    cout << endl;
//}

// Function to print the tree including empty spaces
void printTree() {
    cout << "Tree representation in array form: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (binaryTree[i] == -1) {
            cout << "-1 ";  // Print empty Space
        } else {
            cout << binaryTree[i] << " ";  // Print array
        }
    }
    cout << endl;
}

// Function to find the parent of a node
int findParent(int index) {
    if (index == 0 || binaryTree[index] == -1) {  // display msg: cout << "This node is the root and has no parent." << endl;
        return -1;
    }
    int parent = (index - 1) / 2;
    return binaryTree[parent]; 
}

// Function left child 
int findLeftChild(int index) {
    int leftIndex = 2 * index + 1;
    if (leftIndex < ARRAY_SIZE && binaryTree[leftIndex] != -1) {
        return binaryTree[leftIndex];
    }
    return -1;  // display msg: cout << "No left child." << endl;
}

// Function right child 
int findRightChild(int index) {
    int rightIndex = 2 * index + 2;
    if (rightIndex < ARRAY_SIZE && binaryTree[rightIndex] != -1) {
        return binaryTree[rightIndex];
    }
    return -1;  // display msg: cout << "No Right child." << endl;
}



int main() {
    initTree();  

    int numNodes;
    cout << "Enter the number of nodes to insert: ";
    cin >> numNodes;

    if (numNodes > ARRAY_SIZE) {
        cout << "Cannot insert more than " << ARRAY_SIZE << " nodes." << endl;
        return 1;
    }
    
    for (int i = 0; i < numNodes; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertNode(value);  // Insert the input value into the tree
    }

    printTree();  // Print the array representation of the tree



    // Now, let's demonstrate finding the parent and children of each node
    int index;
    cout << "Enter an index (0 to " << ARRAY_SIZE - 1 << ") to find parent and children: ";
    cin >> index;

    if (index < 0 || index >= ARRAY_SIZE || binaryTree[index] == -1) {
        cout << "Invalid index or no node at that index!" << endl;
    } else {
        int parent = findParent(index);
        int leftChild = findLeftChild(index);
        int rightChild = findRightChild(index);

        cout << "Node value at index " << index << ": " << binaryTree[index] << endl;

        if (parent != -1) {
            cout << "Parent node value: " << parent << endl;
        } else {
            cout << "This node is the root and has no parent." << endl;
        }

        if (leftChild != -1) {
            cout << "Left child node value: " << leftChild << endl;
        } else {
            cout << "No left child." << endl;
        }

        if (rightChild != -1) {
            cout << "Right child node value: " << rightChild << endl;
        } else {
            cout << "No right child." << endl;
        }
    }

    return 0;
}

