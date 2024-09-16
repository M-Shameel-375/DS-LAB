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
   int index;
   int num;
   cout<<"Enter the index of number that change  ";
   cin>>index;
   cout<<"Enter the  number :";
   cin>>num;
   bool found = false;
   for (int i = 0; i < 5; i++)
   {
    if (i==index)
    {
        found=true;
        Array[i]=num;
        cout<<"NUMber Change :"<<endl;
        break;
    }
   }
   if (found==false)
    {
    cout<<"index not found"<<endl;
    }
    cout<<"Number after Change  :";
   for (int i = 0; i < 5; i++)
   {
     cout<<Array[i]<<" ";
   }
   
}