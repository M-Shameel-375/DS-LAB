#include <iostream>
#include <string>
using namespace std;

// Class Definition for Person
class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    // Input function to take person details
    void input() {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Person Name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter Person Age: ";
        cin >> per_age;
    }

    // Output function to display person details
    void output() {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }

    // Getter functions to access private attributes
    int getID() { return per_id; }
};

// Node class for linked list
class Node {
public:
    Person data;
    Node* next;
};

// Queue implementation using Linked List
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a person to the queue
    void addQueue(Person p) {
        Node* temp = new Node();
        temp->data = p;
        temp->next = nullptr;

        if (isEmpty()) {
            front = temp;
            rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    // Remove a person from the queue
    Person removeQueue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            exit(1);
        }
        Node* temp = front;
        front = front->next;
        Person p = temp->data;
        delete temp;
        return p;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            removeQueue();
        }
    }
};

int main() {
    Queue q;
    Person p;
    int choice;

    do {
        cout << "\n1. Add Person to Queue\n2. Remove Person from Queue\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.input();
                q.addQueue(p);
                break;
            case 2:
                if (!q.isEmpty()) {
                    p = q.removeQueue();
                    cout << "Removed Person: ";
                    p.output();
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
