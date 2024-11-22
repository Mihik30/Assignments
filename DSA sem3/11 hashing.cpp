#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;          // Employee ID
    string name;     // Employee Name
    int key;         // Hash key
};

class HashTable {
    Employee Table[10];

public:
    HashTable() {
        for (int i = 0; i < 10; i++) {
            Table[i].key = -1;
            Table[i].id = -1;
            Table[i].name = "";
        }
    }

    int hashValue(int id) {
        return id % 10;
    }

    void insertRecord(int id, string name) {
        int index = hashValue(id);
        int originalIndex = index;

        while (Table[index].key != -1) {
            index = (index + 1) % 10;
            if (originalIndex == index) {
                cout << "Hash table is full. Cannot insert more records." << endl;
                return;
            }
        }
        Table[index].key = originalIndex;
        Table[index].id = id;
        Table[index].name = name;
    }

    void searchRecord(int id) {
        int index = hashValue(id);
        int originalIndex = index;

        while (Table[index].id != id) {
            index = (index + 1) % 10;
            if (Table[index].key == -1 || originalIndex == index) {
                cout << "Record not found for ID: " << id << endl;
                return;
            }
        }
        cout << "Record Found - ID: " << Table[index].id << ", Name: " << Table[index].name << endl;
    }

    void deleteRecord(int id) {
        int index = hashValue(id);
        int originalIndex = index;

        while (Table[index].id != id) {
            index = (index + 1) % 10;
            if (Table[index].key == -1 || originalIndex == index) {
                cout << "Record not found for ID: " << id << endl;
                return;
            }
        }
        cout << "Deleting Record - ID: " << Table[index].id << ", Name: " << Table[index].name << endl;
        Table[index].key = -1;
        Table[index].id = -1;
        Table[index].name = "";
    }

    void displayRecord() {
        for (int i = 0; i < 10; i++) {
            if (Table[i].id != -1) {
                cout << "ID: " << Table[i].id << ", Name: " << Table[i].name << ", Key: " << Table[i].key << endl;
            }
        }
    }
};

int main() {
    int choice = 0, EmpID = 0, wantMore = 1;
    string name;
    cout << "Welcome to Employee Management System!" << endl;
    HashTable h;

    while (wantMore == 1) {
        cout << "\n1. Insert element into the table" << endl;
        cout << "2. Search element by ID" << endl;
        cout << "3. Delete element by ID" << endl;
        cout << "4. Print the Total HashTable" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the EmpID: ";
            cin >> EmpID;
            cout << "Enter the Name: ";
            cin >> name; // Reads a single word for the name

            h.insertRecord(EmpID, name);
        } else if (choice == 2) {
            cout << "Enter the EmpID: ";
            cin >> EmpID;

            h.searchRecord(EmpID);
        } else if (choice == 3) {
            cout << "Enter the EmpID: ";
            cin >> EmpID;

            h.deleteRecord(EmpID);
        } else if (choice == 4) {
            h.displayRecord();
        } else {
            cout << "Enter a valid choice." << endl;
        }
        cout << "Do you want to continue? (1 for yes, 0 for no): ";
        cin >> wantMore;
    }

    return 0;
}
