#include <iostream>
#include <vector>

using namespace std;

const int INSERTION_SORT_THRESHOLD = 10;

// Insertion Sort implementation
void insertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSortLastPivot(vector<int> &arr, int low, int high)
{
    while (low < high)
    {
        if (high - low + 1 < INSERTION_SORT_THRESHOLD)
        {
            insertionSort(arr, low, high);
            break;
        }
        else
        {
            int pivot = arr[high]; // pivot element (last element)
            int i = low - 1;

            for (int j = low; j < high; j++)
            {
                if (arr[j] <= pivot)
                {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            int pi = i + 1;

            if (pi - low < high - pi)
            {
                quickSortLastPivot(arr, low, pi - 1);
                low = pi + 1;
            }
            else
            {
                quickSortLastPivot(arr, pi + 1, high);
                high = pi - 1;
            }
        }
    }
}

void displayArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // Create an array to sort
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arrCopy = arr; // Copy for second method

    quickSortLastPivot(arr, 0, arr.size() - 1);
    cout << "Sorted array (Quick Sort): ";
    displayArray(arr);

    // Sort with Insertion Sort
    insertionSort(arrCopy, 0, arrCopy.size() - 1);
    cout << "Sorted array (Insertion Sort): ";
    displayArray(arrCopy);

    return 0;
}
