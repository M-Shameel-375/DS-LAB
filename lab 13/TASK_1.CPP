#include <iostream>
using namespace std;

class Person
{
private:
    int id;
    string name;
    int age;

public:
    Person() : id(0), name(""), age(0) {}

    void input()
    {
        cout << "\nEnter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void output() const
    {
        cout << "\nPerson Details:\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Node
{
public:
    Person data; 
    Node *next;  

    Node(const Person &p) : data(p), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head; 

public:
    LinkedList() : head(nullptr) {}

    void insertAtFront(const Person &p)
    {
        Node *newNode = new Node(p);
        newNode->next = head;
        head = newNode;
        cout << "Person inserted at the front of the list!\n";
    }

    void display() const
    {
        if (head == nullptr)
        {
            cout << "The list is empty!\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            temp->data.output();
            temp = temp->next;
        }
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    int option;

    while (true)
    {
        cout << "\nLinked List Menu:\n";
        cout << "1. Insert a person at the front\n";
        cout << "2. Display all persons\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1)
        {
            Person p;
            p.input();
            list.insertAtFront(p);
        }
        else if (option == 2)
        {
            list.display();
        }
        else if (option == 3)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
