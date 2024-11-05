#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() { 
    vector<int> arr = {33,12,52,3,75,29,41,6,19};
    int n = arr.size();  

    cout << "Original array: ";
    printArray(arr);
 
    clock_t start= clock();
    quickSort(arr, 0, n - 1);
    clock_t end =clock();
    cout << "Sorted array: ";
    printArray(arr);
     double time_take = double(end - start)/CLOCKS_PER_SEC;
     cout<<"TIME TAKEN BY QUICK SORT:"<<time_take<<"second"<<endl;
     return 0;
    return 0;
}
