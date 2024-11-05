// : Test the Merge Sort function on various arrays and analyze the sorted outputs.

#include <iostream>
#include <vector>

using namespace std;

// Merge function to combine two sorted halves
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid;    
    
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;   
    int j = 0;    
    int k = left; 

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

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

void testMergeSort()
{
    vector<vector<int>> testArrays = {
        {38, 27, 43, 3, 9, 82, 10},
        {12, 11, 13, 5, 6, 7},
        {5, 1, 4, 2, 8},
        {10, 3, 8, 9, 4, 6, 7},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 3, 2, 5, 4},
        {}};

    for (auto &array : testArrays)
    {
        vector<int> arrCopy = array; 
        mergeSort(arrCopy, 0, arrCopy.size() - 1);
        cout << "Sorted array: ";
        displayArray(arrCopy);
    }
}

int main()
{
    testMergeSort();
    return 0;
}
