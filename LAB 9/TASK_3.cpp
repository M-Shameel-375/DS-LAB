#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class Queue
{
private:
    Node *front;       
    Node *rear;       
    int count;         
    const int maxSize; 
public:
    Queue(int size) : front(nullptr), rear(nullptr), count(0), maxSize(size) {}
    bool isEmpty() const
    {
        return front == nullptr;
    }
    bool isFull() const
    {
        return count == maxSize;
    }
    void addQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow: Cannot add more elements. Queue is full.\n";
            return;
        }
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Value " << value << " added to the queue.\n";
    }
    int removeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow: Cannot remove elements. Queue is empty.\n";
            return -1;
        }
        Node *temp = front;
        int removedValue = temp->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        count--;
        return removedValue;
    }
    void displayFront() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            cout << "Front value: " << front->data << "\n";
        }
    }
    void displayQueue() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            Node *temp = front;
            cout << "Queue elements: ";
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};
int main()
{
    Queue queue1(5); 
    Queue queue2(5); 
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert value into Queue 1\n";
        cout << "2. Remove value from Queue 1 (and insert into Queue 2)\n";
        cout << "3. Remove value from Queue 2\n";
        cout << "4. Display Queue 1\n";
        cout << "5. Display Queue 2\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert into Queue 1: ";
            cin >> value;
            queue1.addQueue(value);
            break;

        case 2:
        {
            int removedValue = queue1.removeQueue();
            if (removedValue != -1)
            { 
                queue2.addQueue(removedValue);
                cout << "Value " << removedValue << " moved to Queue 2.\n";
            }
            break;
        }

        case 3:
        {
            int removedValue = queue2.removeQueue();
            if (removedValue != -1)
            {
                cout << "Value " << removedValue << " removed from Queue 2.\n";
            }
            break;
        }

        case 4:
            cout << "Queue 1: ";
            queue1.displayQueue();
            break;

        case 5:
            cout << "Queue 2: ";
            queue2.displayQueue();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
return 0;
}
