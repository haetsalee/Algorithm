#include <iostream>
using namespace std;

int dp[33][2];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int D, K;
    cin >> D >> K;
    
    dp[1][0] = 1, dp[1][1] = 0;
    dp[2][0] = 0, dp[2][1] = 1;
    
    for (int i=3; i<=D ;i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    for (int i=1; i*dp[D][0]<K; i++) {
        int temp = K - (i*dp[D][0]);
        if (temp % dp[D][1] == 0 ) {
            cout << i << "\n";
            cout << temp / dp[D][1] << "\n";
            return 0;
        }
    }
}
