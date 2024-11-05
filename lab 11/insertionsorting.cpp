#include <iostream>
using namespace std;
void insertionsort(int arr[] , int n )
{
        int count =1;
    for (int  i = 1; i < n; i++)
    {
       int key = arr[i];
       int j = i-1;
       while (j>=0 && arr[j]> key )
       {
        arr[j+1] = arr[j];
        j=j-1;
       }
       cout<<endl;
       arr[j+1]= key;
        cout<<"step "<<count <<" :";
        count++;
    for (int  k = 0; k <n; k++)
    {
        cout<< arr[k]<<" ";
    }
    }
    
}
void printarray(int arr[] , int n)
{
    for (int  i = 0; i <n; i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"enter the total  element of  array :";
    cin>>n;
    int arr[n];
    for (int  i = 0; i <n; i++)
    {
        cout<<"Enter the "<<i+1<<" element of array:";
        cin>> arr[i];
    }
    cout<<"original array :"<<endl;
    printarray(arr ,n);
    insertionsort(arr , n);
     cout<<"\nsorted array :"<<endl;
    printarray(arr , n);
}