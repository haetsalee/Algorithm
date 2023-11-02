#include <iostream>
using namespace std;

int main()
{
    int T, S;
    cin >> T >> S;
    
    int result = 280;
    
    if (T >= 12 && T<= 16) {
        if (S == 0)
            result = 320;
    }
    
    cout << result;
}