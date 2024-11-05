#include<iostream>
using namespace std;

// Insertion Sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Function to display the array

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int array1[10] = {25, 47, 3, 19, 8, 55, 23, 4, 72, 36};
    int array2[10] = {99, 1, 82, 74, 60, 45, 33, 20, 11, 5};
    int array3[10] = {13, 5, 27, 18, 65, 43, 21, 39, 84, 7};
    int n = 10;

    cout << "\nArray 1" << endl;
    insertionSort(array1, n);
    display(array1, n);

    cout << "\nArray 2" << endl;
    insertionSort(array2, n);
    display(array2, n);

    cout << "\nArray 3" << endl;
    insertionSort(array3, n);
    display(array3, n);

    return 0;
}
