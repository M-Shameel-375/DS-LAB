#include <iostream>
#include <vector>
using namespace std;

void quickSortLastPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
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

        quickSortLastPivot(arr, low, pi - 1);
        quickSortLastPivot(arr, pi + 1, high);
    }
}

void quickSortFirstPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low];
        int i = high + 1;

        for (int j = high; j > low; j--)
        {
            if (arr[j] >= pivot)
            {
                i--;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i - 1], arr[low]);
        int pi = i - 1;

        quickSortFirstPivot(arr, low, pi - 1);
        quickSortFirstPivot(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr1 = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arr2 = arr1;

    cout << "Original array: ";
    for (int i : arr1) cout << i << " ";
    cout << endl;

    quickSortLastPivot(arr1, 0, arr1.size() - 1);
    cout << "Sorted array (Last Element as Pivot): ";
    for (int i : arr1) cout << i << " ";
    cout << endl;

    quickSortFirstPivot(arr2, 0, arr2.size() - 1);
    cout << "Sorted array (First Element as Pivot): ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    return 0;
}
