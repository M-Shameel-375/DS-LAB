#include<iostream>
using namespace std;
int main()
{
    int size,sum=0;
    cout<<"Enter Array Size from 1 to 20 : ";
    cin>>size;
    int array[size];
    cout << "\nEnter values (0 to 12): "<<endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> array[i];
    }
    for(int i=0; i<size; i++)
    {
        sum+=array[i];
    }
    float avg=sum/size;
    cout<<"Average Of Array is : "<<avg;
    cout << "Factorials of the array elements:" << endl;
    for (int i = 0; i < size; i++) 
    {
        int num = array[i];
        int fac = 1;

        for (int j = num; j > 0; j--) 
        {
            fac *= j;
        }

        cout << "Factorial of " << num << " =  " << fac << endl;
    }
}