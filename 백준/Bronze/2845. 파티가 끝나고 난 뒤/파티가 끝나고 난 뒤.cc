#include <iostream>
using namespace std;

int main()
{
    int L, P, news;
    cin >> L >> P;
    int people = L * P;
    
    for (int i=0; i<5; i++) {
        cin >> news;
        cout << news - people << " ";
    }
}