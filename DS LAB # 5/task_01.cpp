#include <iostream>
using namespace std;

void arrayInsert(int arr[], int &size, int pos, int val)
{
    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
}


void arrayDelete(int arr[], int &size, int pos)
{
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

void linkedListInsertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void linkedListDeleteAtHead(Node *&head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    cout << "Array before insertion: ";
    displayArray(arr, size);

    arrayInsert(arr, size, 2, 99);
    cout << "Array after insertion: ";
    displayArray(arr, size);
    arrayDelete(arr, size, 2);
    cout << "Array after deletion: ";
    displayArray(arr, size);

    Node *head = NULL;
    linkedListInsertAtHead(head, 5);
    linkedListInsertAtHead(head, 10);
    linkedListInsertAtHead(head, 15);
    cout << "Linked List before deletion: ";
    displayLinkedList(head);

    linkedListDeleteAtHead(head);
    cout << "Linked List after deletion: ";
    displayLinkedList(head);

    return 0;
}
