#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    // Constructor
    Student() : reg_no(0), st_name(""), cgpa(0.0) {}

    // Input function to take student details
    void input() {
        cout << "Enter Registration Number: ";
        cin >> reg_no;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, st_name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    // Output function to display student details
    void output() {
        cout << "Reg No: " << reg_no << ", Name: " << st_name << ", CGPA: " << cgpa << endl;
    }
};
class Stack {
private:
    Student* arr; 
    int top;
    int maxSize;

public:
    Stack(int size) {
        maxSize = size;
        arr = new Student[maxSize];
        top = -1;
    }

    // Push student object onto the stack
    void push(Student s) {
        if (top == maxSize - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = s;
    }

    // Pop student object from the stack
    Student pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            exit(1);
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);
    Student s;
    int choice;

    do {
        cout << "\n1. Push Student\n2. Pop Student\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.input();
                stack.push(s);
                break;
            case 2:
                if (!stack.isEmpty()) {
                    s = stack.pop();
                    cout << "Popped Student: ";
                    s.output();
                }
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
