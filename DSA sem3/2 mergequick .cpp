#include <iostream>
using namespace std;

struct Employee {
    int id;
    char name[50];
    float salary;
};

int partition(Employee employees[], int start, int end) {
    int pivot = employees[end].id;
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (employees[j].id < pivot) {
            ++i;
            swap(employees[i], employees[j]);
        }
    }
    swap(employees[i + 1], employees[end]);
    return i + 1;
}

void quickSort(Employee employees[], int start, int end) {
    if (start < end) {
        int pi = partition(employees, start, end);
        quickSort(employees, start, pi - 1);
        quickSort(employees, pi + 1, end);
    }
}

bool compareNames(char name1[], char name2[]) {
    int i = 0;
    while (name1[i] != '\0' && name2[i] != '\0') {
        if (name1[i] < name2[i]) {
            return true;
        } else if (name1[i] > name2[i]) {
            return false;
        }
        ++i;
    }
    return name1[i] < name2[i];
}

void merge(Employee employees[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Employee* leftArr = new Employee[n1];
    Employee* rightArr = new Employee[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = employees[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = employees[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareNames(leftArr[i].name, rightArr[j].name)) {
            employees[k] = leftArr[i];
            ++i;
        } else {
            employees[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        employees[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        employees[k] = rightArr[j];
        ++j;
        ++k;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(Employee employees[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(employees, left, middle);
        mergeSort(employees, middle + 1, right);
        merge(employees, left, middle, right);
    }
}

int main() {
    int numberOfEmployees;
    cout << "Enter the number of employees: ";
    cin >> numberOfEmployees;

    Employee employees[numberOfEmployees];

    for (int i = 0; i < numberOfEmployees; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        cout << "Enter EMP-ID: ";
        cin >> employees[i].id;
        cout << "Enter EMP-Name: ";
        cin >> employees[i].name;
        cout << "Enter EMP-Salary: ";
        cin >> employees[i].salary;
    }

    cout << "\nOriginal Employee List:\n";
    cout << "EMP-ID\tEMP-Name\tEMP-Salary\n";
    for (int i = 0; i < numberOfEmployees; ++i) {
        cout << employees[i].id << "\t" << employees[i].name << "\t\t" << employees[i].salary << endl;
    }

    quickSort(employees, 0, numberOfEmployees - 1);
    cout << "\nEmployees sorted by EMP-ID (Quick Sort):\n";
    cout << "EMP-ID\tEMP-Name\tEMP-Salary\n";
    for (int i = 0; i < numberOfEmployees; ++i) {
        cout << employees[i].id << "\t" << employees[i].name << "\t\t" << employees[i].salary << endl;
    }

    mergeSort(employees, 0, numberOfEmployees - 1);
    cout << "\nEmployees sorted by EMP-Name (Merge Sort):\n";
    cout << "EMP-ID\tEMP-Name\tEMP-Salary\n";
    for (int i = 0; i < numberOfEmployees; ++i) {
        cout << employees[i].id << "\t" << employees[i].name << "\t\t" << employees[i].salary << endl;
    }

    return 0;
}
