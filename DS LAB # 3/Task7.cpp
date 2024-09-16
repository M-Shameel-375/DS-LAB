#include <iostream>
using namespace std;
int main() 
{
    int n, key;
    int position =0;
    bool found=true;
    cout << "Enter the size of the array: ";
    cin >> n;
    int array[n];
    cout << "Enter " << n << " elements of the array:" << endl;
    for(int i = 0; i < n; i++) 
    {
        cin >> array[i];
    }
    cout << "Enter the key value to search: ";
    cin >> key;
    for(int i = 0; i < n; i++) 
    {
        if(array[i] == key) {
            position = i;
            found=false;
            break;
        }
    }
    if(found== false) 
    {
        cout << " value found at position " << position<< " in the array." << endl;
    } 
    else 
    {
        cout << "value not found in the array." << endl;
    }
    return 0;
}