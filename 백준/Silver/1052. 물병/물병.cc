#include<iostream>
using namespace std;
 
int N, K;
 
int solve(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1)
            cnt++;
        x /= 2;
    }
    return cnt;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
 
    int result = N;
    
    while (true) {
        if (solve(result) <= K)
            break;
        else
            result++;
    }
    
    cout << result - N;
}