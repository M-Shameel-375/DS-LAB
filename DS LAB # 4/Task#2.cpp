#include<iostream>
using namespace std;
int binarysearch(int arr[], int size , int target)
{
    int low = 0;
    int high =  size-1;
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if (arr[mid]>target)
        {
            high = mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    cout << "\n\n****** DSA LAB 4 ***** \n\n";
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"Given element of array :"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    int size;
    size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "\nEnter the value to be search: " << "\t";
    cin >> target;
    int result = binarysearch(arr, size, target);
    if (result != -1)
    {
        cout << "Element " << target << " found at index " << result << endl;
    }
    else
    {
        cout <<" Element "<<target<<" not found in the array " << endl;
    }
    return 0;
}