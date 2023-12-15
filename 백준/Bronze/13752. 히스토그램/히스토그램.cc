#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int num;
        cin >> num;
        
        for (int i=0; i<num; i++) {
            cout << "=";
        }
        cout << "\n";
    }
    return 0;
}
