
#include <iostream>
#include <vector>
#include <ctime>    

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

void quickSortRandomPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);

        cout << "Random pivot selected: index " << randomIndex 
             << " (value " << arr[high] << ")" << endl;

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

        quickSortRandomPivot(arr, low, pi - 1);
        quickSortRandomPivot(arr, pi + 1, high);
    }
}

int main()
{
    
    srand(time(0));

    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arrCopy = arr; 

    quickSortLastPivot(arr, 0, arr.size() - 1);
    cout << "Sorted array (Last Element as Pivot): ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    quickSortRandomPivot(arrCopy, 0, arrCopy.size() - 1);
    cout << "Sorted array (Random Element as Pivot): ";
    for (int i : arrCopy) cout << i << " ";
    cout << endl;

    return 0;
}
