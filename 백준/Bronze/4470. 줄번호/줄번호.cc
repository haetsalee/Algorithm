#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    for (int i=1; i<=N; i++) {
        string temp;
        getline(cin, temp);
        
        cout << i << ". " << temp << "\n";
    }
}