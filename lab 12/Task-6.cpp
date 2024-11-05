#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Merge Sort functions
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort functions
void quickSort(vector<int> &arr, int low, int high)
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

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
    return arr;
}

void displayArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Performance testing function
void testSortingAlgorithms(int size)
{
    vector<int> randomArray = generateRandomArray(size);
    vector<int> mergeSortArray = randomArray; 
    vector<int> quickSortArray = randomArray; 

    // Measure Merge Sort
    clock_t start = clock();
    mergeSort(mergeSortArray, 0, mergeSortArray.size() - 1);
    clock_t end = clock();
    double mergeSortTime = double(end - start) / CLOCKS_PER_SEC;

    // Measure Quick Sort
    start = clock();
    quickSort(quickSortArray, 0, quickSortArray.size() - 1);
    end = clock();
    double quickSortTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Size: " << size << "\n";
    cout << "Merge Sort Time: " << mergeSortTime << " seconds\n";
    cout << "Quick Sort Time: " << quickSortTime << " seconds\n";
    cout << "------------------------------------\n";
}

int main()
{
    srand(time(0)); // Initialize random seed

    // Test with different sizes
    for (int size : {100, 1000, 10000, 100000})
    {
        testSortingAlgorithms(size);
    }

    return 0;
}
