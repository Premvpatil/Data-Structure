#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to add a student to the file
void addStudent() {
    ofstream outFile("students.txt", ios::app);  // Open file in append mode
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string name;
    int rollNumber;
    float grade;

    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cin.ignore();  // Ignore leftover newline
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Grade: ";
    cin >> grade;

    outFile << rollNumber << "\n" << name << "\n" << grade << "\n";
    outFile.close();
    cout << "Student added successfully!" << endl;
}

// Function to display all students
void displayStudents() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "No data found!" << endl;
        return;
    }

    int rollNumber;
    string name;
    float grade;

    while (inFile >> rollNumber) {
        inFile.ignore();  // Ignore newline after roll number
        getline(inFile, name);  // Get the name
        inFile >> grade;  // Get the grade

        cout << "Roll Number: " << rollNumber << ", Name: " << name << ", Grade: " << grade << endl;
        inFile.ignore();  // Ignore newline after grade
    }

    inFile.close();
}

// Function to delete a student
void deleteStudent() {
    int rollNumber;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumber;

    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");  // Temporary file to store data without the deleted student

    if (!inFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int tempRollNumber;
    string name;
    float grade;
    bool found = false;

    while (inFile >> tempRollNumber) {
        inFile.ignore();
        getline(inFile, name);
        inFile >> grade;
        inFile.ignore();

        if (tempRollNumber == rollNumber) {
            found = true;  // Skip the student to delete
        } else {
            tempFile << tempRollNumber << "\n" << name << "\n" << grade << "\n";  // Copy the rest
        }
    }

    inFile.close();
    tempFile.close();

    // Replace the original file with the new file
    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nStudent Information System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
