#include <iostream>
#include <climits> // Include for INT_MAX
using namespace std;

// Node structure for the queue
struct Node
{
    int data;
    Node *next;
};

// Queue class using a linked list
class Queue
{
private:
    Node *front;
    Node *rear;
    int size;
    int maxSize; // Maximum size for overflow handling

public:
    // Constructor
    Queue(int maxQueueSize = INT_MAX) : front(nullptr), rear(nullptr), size(0), maxSize(maxQueueSize) {}

    // Destructor
    ~Queue()
    {
        clear();
    }

    // Enqueue operation
    void enqueue(int value)
    {
        if (size == maxSize)
        {
            cout << "\tQueue Overflow! Cannot add more elements." << endl;
            return;
        }
        Node *newNode = new Node{value, nullptr};
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Dequeue operation
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "\tQueue Underflow! No elements to remove." << endl;
            return -1;
        }
        Node *temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Count elements in the queue
    int count() const
    {
        return size;
    }

    // Clear the queue
    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Display all elements in the queue
    void display() const
    {
        if (isEmpty())
        {
            cout << "\tQueue is empty!" << endl;
            return;
        }
        Node *current = front;
        cout << "\tQueue Elements: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test the queue
int main()
{
    Queue q(5); // Set maximum size to 5
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "\tNumber of elements in the queue: " << q.count() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Should trigger overflow
    q.display();

    cout << "\tDequeued: " << q.dequeue() << endl;
    q.display();

    cout << "\tClearing the queue..." << endl;
    q.clear();
    q.display();
    cout << "\tNumber of elements in the queue after clearing: " << q.count() << endl;

    return 0;
}
