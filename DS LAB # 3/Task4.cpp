#include<iostream>
using namespace std;

int main()
{
   int Array[5];
   cout<<"Enter the Five number :";
   for (int i = 0; i < 5; i++)
   {
     cin>>Array[i];
   }
    int num;
    cout<<"Enter the Element you want to Delete : ";
    cin>>num;

    for (int i = num; i < 5-1; i++)
    {
        Array[i]=Array[i+1];
    }

    cout<<"After Deletion : "<<endl;
    for (int i = 0; i < 5-1; i++)
    {
        cout<<Array[i]<<" "<<endl;
    }
    
    return 0;
}