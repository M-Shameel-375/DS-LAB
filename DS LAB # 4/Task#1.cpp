#include<iostream>
using namespace std;
int linearsearch(int arr[], int size ,int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==target)
        {
            return i;
        }
        
    }
    return -1;
    
}
int main ()
{
    int arr[10]={1,23,43,54,67,89,3,5,76,89};
    size=sizeof(arr)/sizeof(arr[0]);
    int result = linearsearch(arr , size , target );
    if (result!=-1)
    {
        Cout
    }
    
}