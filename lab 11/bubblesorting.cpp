#include <iostream>
using namespace std;

void bubblesort(int arr[], int n) {
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout << endl;
        cout << "step " << count << " :";
        count++;
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
    }
}

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the total elements of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << " element of the array: ";
        cin >> arr[i];
    }
    cout << "Original array:" << endl;
    printarray(arr, n);
    bubblesort(arr, n);
    cout << "\nSorted array:" << endl;
    printarray(arr, n);
    return 0;
}
