#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store employee information
struct Employee {
    int id;
    string name;
    string department;
    string address;
};

// Function to add an employee's information to the file
void addEmployee() {
    ofstream outFile("employees.txt", ios::app);  // Open file in append mode
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore();  // Ignore leftover newline
    cout << "Enter Employee Name: ";
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Address: ";
    getline(cin, emp.address);

    outFile << emp.id << "\n" << emp.name << "\n" << emp.department << "\n" << emp.address << "\n";
    outFile.close();
    cout << "Employee added successfully!" << endl;
}

// Function to display all employee records
void displayEmployees() {
    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "No data found!" << endl;
        return;
    }

    Employee emp;
    while (inFile >> emp.id) {
        inFile.ignore();  // Ignore newline after employee ID
        getline(inFile, emp.name);
        getline(inFile, emp.department);
        getline(inFile, emp.address);

        cout << "Employee ID: " << emp.id << ", Name: " << emp.name << ", Department: " << emp.department << ", Address: " << emp.address << endl;
    }

    inFile.close();
}

// Function to update employee information
void updateEmployee() {
    int idToUpdate;
    cout << "Enter Employee ID to update: ";
    cin >> idToUpdate;

    ifstream inFile("employees.txt");
    ofstream tempFile("temp.txt");  // Temporary file to store updated data

    if (!inFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;
    bool found = false;
    while (inFile >> emp.id) {
        inFile.ignore();  // Ignore newline after employee ID
        getline(inFile, emp.name);
        getline(inFile, emp.department);
        getline(inFile, emp.address);

        if (emp.id == idToUpdate) {
            found = true;
            cin.ignore();  // To clear the newline left by cin
            cout << "Enter new Name: ";
            getline(cin, emp.name);
            cout << "Enter new Department: ";
            getline(cin, emp.department);
            cout << "Enter new Address: ";
            getline(cin, emp.address);
        }

        // Write the updated or original data to the temporary file
        tempFile << emp.id << "\n" << emp.name << "\n" << emp.department << "\n" << emp.address << "\n";
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("employees.txt");  // Remove the old file
        rename("temp.txt", "employees.txt");  // Rename the temp file to original file
        cout << "Employee information updated!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

// Function to delete an employee's record
void deleteEmployee() {
    int idToDelete;
    cout << "Enter Employee ID to delete: ";
    cin >> idToDelete;

    ifstream inFile("employees.txt");
    ofstream tempFile("temp.txt");  // Temporary file to store data without the deleted employee

    if (!inFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Employee emp;
    bool found = false;
    while (inFile >> emp.id) {
        inFile.ignore();  // Ignore newline after employee ID
        getline(inFile, emp.name);
        getline(inFile, emp.department);
        getline(inFile, emp.address);

        if (emp.id == idToDelete) {
            found = true;
            cout << "Employee with ID " << idToDelete << " deleted!" << endl;
        } else {
            // Copy the employee record to the temporary file
            tempFile << emp.id << "\n" << emp.name << "\n" << emp.department << "\n" << emp.address << "\n";
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("employees.txt");  // Remove the old file
        rename("temp.txt", "employees.txt");  // Rename the temp file to original file
    } else {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nEmployee Information System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
