#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Node {
public:
    int id;
    string name;
    int marks[10];
    Node* next;

    Node(int idVal, string nameVal, int marksVal[10]) {
        id = idVal;
        name = nameVal;
        for (int i = 0; i < 10; i++) {
            marks[i] = marksVal[i];
        }
        next = nullptr;
    }
};

void insertAtHead(Node*& head, int id, string name, int marks[10]) {
    Node* newNode = new Node(id, name, marks);
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    cout << "SAP ID\tName\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->id << "\t" << temp->name << "\t";
        for (int i = 0; i < 10; i++) {
            cout << temp->marks[i] << "\t";
        }
        cout << endl;
        temp = temp->next;
    }
}

void swapNodeData(Node* a, Node* b) {
    int tempId = a->id;
    string tempName = a->name;
    int tempMarks[10];
    for (int i = 0; i < 10; i++) {
        tempMarks[i] = a->marks[i];
    }

    a->id = b->id;
    a->name = b->name;
    for (int i = 0; i < 10; i++) {
        a->marks[i] = b->marks[i];
    }

    b->id = tempId;
    b->name = tempName;
    for (int i = 0; i < 10; i++) {
        b->marks[i] = tempMarks[i];
    }
}

void selectionSort(Node*& head, bool ascending = true) {
    Node* current = head;
    while (current != nullptr) {
        Node* minOrMax = current;
        Node* nextNode = current->next;

        // Find the min/max node in the unsorted part of the list
        while (nextNode != nullptr) {
            if ((ascending && nextNode->id < minOrMax->id) || (!ascending && nextNode->id > minOrMax->id)) {
                minOrMax = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap the data of the current node with the min/max node found
        if (minOrMax != current) {
            swapNodeData(current, minOrMax);
        }

        current = current->next;
    }
}

void loadDataFromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        istringstream iss(line);

        int id;
        string name;
        int marks[10];

        iss >> id >> name;
        for (int i = 0; i < 10; i++) {
            iss >> marks[i];
        }

        insertAtHead(head, id, name, marks);
    }
    file.close();
}

int main() {
    Node* head = nullptr;

    loadDataFromFile(head, "students.txt");

    cout << "Original List:\n";
    display(head);

    selectionSort(head, true);
    cout << "\n\nList Sorted in Ascending Order (Selection Sort):\n";
    display(head);

    selectionSort(head, false);
    cout << "\n\nList Sorted in Descending Order (Selection Sort):\n";
    display(head);

    return 0;
}
