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
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
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

    void append(const Person &p)
    {
        Node *newNode = new Node(p);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Person added to the list!" << endl;
    }

    void displayAll() const
    {
        if (!head)
        {
            cout << "The list is empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            temp->data.display();
            temp = temp->next;
        }
    }

    void deleteList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All nodes have been deleted!" << endl;
    }

    ~LinkedList()
    {
        deleteList();
    }
};

int main()
{
    LinkedList list;
    int option;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Person\n";
        cout << "2. Display All Persons\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            Person p;
            p.input();
            list.append(p);
            break;
        }
        case 2:
            list.displayAll();
            break;
        case 3:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
        }
    } while (option != 3);

    return 0;
}
