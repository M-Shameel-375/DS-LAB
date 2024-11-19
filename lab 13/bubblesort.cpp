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
    // Swap id, name, and marks array between nodes a and b
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

void bubbleSort(Node*& head, bool ascending = true) {
    if (!head || !head->next)
        return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if ((ascending && current->id > current->next->id) || (!ascending && current->id < current->next->id)) {
                swapNodeData(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
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

    bubbleSort(head, true);
    cout << "\n\nList Sorted in Ascending Order (Bubble Sort):\n";
    display(head);

    bubbleSort(head, false);
    cout << "\n\nList Sorted in Descending Order (Bubble Sort):\n";
    display(head);

    return 0;
}
