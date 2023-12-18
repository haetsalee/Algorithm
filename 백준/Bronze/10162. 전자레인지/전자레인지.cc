#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    int A = 0, B = 0, C = 0;
    cin >> T;
    
    if(T % 10 != 0) {
        cout << -1;
        return 0;
    }
    
    A = T / 300;
    T = T % 300;
    B = T / 60;
    T = T % 60;
    C = T / 10;
    
    cout << A << " " << B << " " << C;
    
    return 0;
}