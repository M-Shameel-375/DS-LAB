#include <iostream>
using namespace std;

int main() 
{
    int matrix[3][3];
    // int sMatrix[3][3];
    cout << "Enter the elements of the 3x3 matrix:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    // for(int i = 0; i < 3; i++) 
    // {
    //     for(int j = 0; j < 3; j++) 
    //     {
    //         sMatrix[j][i] = matrix[i][j];
    //     }
    // }
    cout << "\nThe transposed matrix is:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}