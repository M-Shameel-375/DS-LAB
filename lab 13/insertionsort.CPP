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
    Node* temp = head;

    cout << "SAP ID\tName\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";


    while (temp != nullptr) {
        cout << temp->id << "\t" << temp->name << "\t";
        for (int i = 0; i < 10; i++) {
            cout << temp->marks[i] << "\t";
        }
        cout << endl;
        temp = temp->next;
    }
}

void saveToFile(Node* head, const string& filename, const string& order) {
    ofstream file(filename, ios::app);  // Open in append mode
    if (file.is_open()) {
        file << "List Sorted in " << order << " Order:\n";
        file << "SAP ID\tName\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";
        Node* temp = head;
        while (temp != nullptr) {
            file << temp->id << "\t" << temp->name << "\t";
            for (int i = 0; i < 10; i++) {
                file << temp->marks[i] << "\t";
            }
            file << endl;
            temp = temp->next;
        }
        file << "----------------------------------------------------------------------------------------------------\n\n";
        file.close();
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}

void insertionSort(Node*& head, bool ascending = true) {
    if (!head || !head->next)
        return;

    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        if (sorted == nullptr || (ascending && current->id < sorted->id) || (!ascending && current->id > sorted->id)) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && ((ascending && temp->next->id < current->id) || (!ascending && temp->next->id > current->id))) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted; 
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

    insertionSort(head, true);
    cout << "\n\nList Sorted in Ascending Order:\n";
    display(head);
    saveToFile(head, "sorted_students.txt", "Ascending");

    insertionSort(head, false);
    cout << "\n\nList Sorted in Descending Order:\n";
    display(head);
    saveToFile(head, "sorted_students.txt", "Descending");


    return 0;
}
