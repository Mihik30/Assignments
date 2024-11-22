#include <iostream>
using namespace std;

// Node structure representing a term in the polynomial
struct Node {
    int coeff;    // Coefficient of the term
    int power;    // Power of the term
    Node* next;   // Pointer to the next term
};

// Student class for handling polynomial operations
class Student {
    Node* head;   // Pointer to the head of the polynomial linked list
    Node* tail;   // Pointer to the tail of the polynomial linked list

public:
    // Constructor to initialize an empty polynomial
    Student() {
        head = nullptr;
        tail = nullptr;
    }

    void add_end(int c, int p) {
        Node* newNode = new Node;
        newNode->coeff = c;
        newNode->power = p;
 
        newNode -> next = head;
        head = newNode;
        
    }

    // Method to perform polynomial addition
    void Polynomial(Student list1, Student list2) {
        Student result;         // Resultant polynomial
        Node* ptr1 = list1.head; // Pointer for traversing list1
        Node* ptr2 = list2.head; // Pointer for traversing list2

        // Traverse both polynomials simultaneously
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->power == ptr2->power) {
                
                // Add coefficients of terms with the same power
                
                result.add_end(ptr1->coeff + ptr2->coeff, ptr1->power);
                
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } else if (ptr1->power > ptr2->power) {
                
                // Add the term from list1 if it has higher power
                
                result.add_end(ptr1->coeff, ptr1->power);
                
                ptr1 = ptr1->next;
            } 
            else 
            {
                // Add the term from list2 if it has higher power
                result.add_end(ptr2->coeff, ptr2->power);
                ptr2 = ptr2->next;
            }
        }

        // Append remaining terms of list1
        while (ptr1 != nullptr) {
            result.add_end(ptr1->coeff, ptr1->power);
            ptr1 = ptr1->next;
        }

        // Append remaining terms of list2
        while (ptr2 != nullptr) {
            result.add_end(ptr2->coeff, ptr2->power);
            ptr2 = ptr2->next;
        }

        // Display the result polynomial
        Node* ptr3 = result.head;
        while (ptr3 != nullptr) 
        {
            cout << ptr3->coeff << "x^" << ptr3->power;
            if (ptr3->next != nullptr) cout << " + ";
            ptr3 = ptr3->next;
        }
        cout << endl;
    }
};

int main() 
{
    Student s1; // Polynomial 1
    Student s2; // Polynomial 2
    int c, p, x, y;

    // Input for the first term of polynomial 1
    cout << "Enter value of coefficient: ";
    cin >> c;
    cout << "Enter power: ";
    cin >> p;

    // Input for the first term of polynomial 2
    cout << "Enter value of coefficient: ";
    cin >> x;
    cout << "Enter power: ";
    cin >> y;

    // Adding terms to the respective polynomials
    s1.add_end(c, p);
    s2.add_end(x, y);

    // Perform and display the result of polynomial addition
    s2.Polynomial(s1, s2);

    return 0;
}
