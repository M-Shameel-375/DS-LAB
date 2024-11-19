#include <iostream>
#include <string>
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
        cout << "\nEnter person ID: ";
        cin >> id;
        cout << "Enter person name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter person age: ";
        cin >> age;
    }

    void display() const
    {
        cout << "\nPerson details:\n";
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

    void insertAtHead(const Person &p)
    {
        Node *newNode = new Node(p);
        newNode->next = head;
        head = newNode;
        cout << "Person inserted at the head of the list!\n";
    }

    void insertAtTail(const Person &p)
    {
        Node *newNode = new Node(p);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Person inserted at the tail of the list!\n";
    }

    void displayList() const
    {
        if (head == nullptr)
        {
            cout << "The list is empty!\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            temp->data.display();
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
    int choice;

    while (true)
    {
        cout << "\nLinked List Menu:\n";
        cout << "1. Insert a person at the head\n";
        cout << "2. Insert a person at the tail\n";
        cout << "3. Display all persons\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Person p;
            p.input();
            list.insertAtHead(p);
            break;
        }
        case 2:
        {
            Person p;
            p.input();
            list.insertAtTail(p);
            break;
        }
        case 3:
            list.displayList();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    cout << "\n\n\tAbrar Ali\n\tID: 55843";

    return 0;
}
