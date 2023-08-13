#include <iostream>
using namespace std;

int main()
{
    int H, M, S, times;
    cin >> H >> M >> S >> times;
    
    S += times;
    
    if (S > 59) {
        M += (S / 60);
        S %= 60;
    }
    if (M > 59) {
        H += (M / 60);
        M %= 60;
    }
    if (H > 23) {
        H %= 24;
    }
    
    cout << H << " " << M << " " << S;
}