#include<iostream>
using namespace std;
int main() 
{
    int n=6;
    int array[n];
    cout << "\nEnter 6 integer values: "<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> array[i];
    }

    bool Palindrome = true;
    for (int i = 0; i < n / 2; i++) 
    {
        if (array[i] != array[n - 1 - i]) 
        {
            Palindrome = false;
            break;
        }
    }
    if (Palindrome) 
    {
        cout << "The array represents a palindrome." << endl;
    } 
    else 
    {
        cout << "The array does not represent a palindrome." << endl;
    }
    return 0;
}