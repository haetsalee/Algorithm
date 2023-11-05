#include <iostream>
using namespace std;

int main()
{
    int totalA = 0, totalB = 0;
    
    for (int i=0; i<4; i++) {
        int score;
        cin >> score;
        totalA += score;
    }
    
    for (int i=0; i<4; i++) {
        int score;
        cin >> score;
        totalB += score;
    }
    
    if (totalA >= totalB) {
        cout << totalA;
    }
    
    else cout << totalB;
}