#include <iostream>
using namespace std;

int main() {
    int sValue;
    int numbers[4][4] = {{12, 34, 23, 34},{78, 56, 89, 12},{34, 12, 45, 67},{90, 23, 56, 78}};
       for(int i =0; i < 4; i++)
    {
        for(int j =0; j < 4; j++)
        {
            cout<<numbers[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Enter Search Value: ";
    cin >> sValue;
    bool found = false;
 
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j) 
        {
            if (numbers[i][j] == sValue) 
            {
                cout << "*** Search Found at (" << i << ", " << j << ") ***" << endl;
                found = true;
                break;
            }
            break;
        }
    }
    if (found == false) 
    {
        cout << "*** Search Not Found ***" << endl;
    }

    return 0;
}