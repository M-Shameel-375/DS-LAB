#include <iostream>
#include <vector>
#include <cstdlib>  
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

void measurePerformance(int size)
{
    vector<int> arr(size);
    for (int &num : arr) {
        num = rand() % 10000; 
    }

    vector<int> arrCopy = arr; 

    cout << "\nArray Size: " << size << endl;

    clock_t start = clock();
    quickSortLastPivot(arr, 0, arr.size() - 1);
    clock_t end = clock();
    double timeLastPivot = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time (Last Element as Pivot): " << timeLastPivot << " seconds" << endl;

    start = clock();
    quickSortRandomPivot(arrCopy, 0, arrCopy.size() - 1);
    end = clock();
    double timeRandomPivot = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time (Random Element as Pivot): " << timeRandomPivot << " seconds" << endl;
}

int main()
{
    srand(time(0));

    measurePerformance(100);    
    measurePerformance(1000);    
    measurePerformance(10000);  

    return 0;
}
