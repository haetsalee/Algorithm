#include<iostream>
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) 
            cout << " ";
        
        for (int k = 0; k < (N - i) * 2 - 1; k++)
            cout << "*";
        
        cout << "\n";
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = N - 1; j > i; j--)
            cout << " ";
        
        for (int k = 0; k < (i + 1) * 2 - 1; k++)
            cout << "*";
        
        cout << "\n";
    }
}