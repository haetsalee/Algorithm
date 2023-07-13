#include <iostream>
using namespace std; 

int main() {
    int N;
    
    while (cin >> N) {
        int num = 1;
        int cnt = 1;
        
        while (true) {
            if (num % N == 0) break;
            
            cnt++;
            num = num * 10 + 1;
            num %= N;
        }
        cout << cnt << "\n";
    }
}