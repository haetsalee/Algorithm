#include <iostream>
using namespace std;

#define MOD 1000000007
long long dp[1001][1001];

int main() 
{
    int N, M;
    cin >> N >> M;
    dp[1][1] = 1;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
        }
    }
    
    cout << dp[N][M];
    
    return 0;
}