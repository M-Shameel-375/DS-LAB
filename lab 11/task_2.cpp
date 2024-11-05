#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int array1[10] = {12, 45, 23, 89, 67, 34, 2, 78, 5, 90};
    int array2[10] = {1, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int array3[10] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 10;

    cout << "Bubble Sort Array 1" << endl;
    bubbleSort(array1, n);
    display(array1, n);

    cout << "Bubble Sort Array 2" << endl;
    bubbleSort(array2, n);
    display(array2, n);

    cout << "Bubble Sort Array 3" << endl;
    bubbleSort(array3, n);
    display(array3, n);

    return 0;
}
