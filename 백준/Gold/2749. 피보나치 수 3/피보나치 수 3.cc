#include <iostream>
using namespace std;

#define MAX 1500000

long long dp[MAX];
int mod = 1000000;

void fibo() {
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i=2; i<MAX; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
}
 
int main() {
    long long N;
    cin >> N;
    
    fibo();
    
    cout << dp[N % MAX] << "\n";
}
