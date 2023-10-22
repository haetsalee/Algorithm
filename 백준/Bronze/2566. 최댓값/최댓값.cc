#include <iostream>
using namespace std;

int arr[10][10];

int main()
{
    int max = 0, row = 0, column = 0;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= max) {
                max = arr[i][j];
                row = i+1;
                column = j+1;
            }
        }
    }
    
    cout << max << "\n" << row << " " << column;
}
