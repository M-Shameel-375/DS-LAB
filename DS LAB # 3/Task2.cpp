#include<iostream>
using namespace std;
int main()
{
    int SearchValue;
    cout<<" Enter search value  :"<<endl;
    cin>>SearchValue;
    bool found = false;
    int number[5]={12,14,10,15,17};
    for (int  i = 0; i < 5; i++)
    {
      if (number[i]==SearchValue)
      {
        found=true;
        cout<<"  **** Search found ***"<<endl;
        cout<<"The index of search number    :"<<i;
        break;
      }
    }
    if (found==false)
    {
       cout<<"  **** Search not found ***"<<endl; 
    }
    
    return 0;
}