#include <iostream>
using namespace std;

#define MAX 100001
#define MOD 1000000009

int dp[MAX][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    
    for (int i=4; i<=MAX; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }

    int N;
    cin >> N;
    
    while (N--) {
        int num;
        cin >> num;
        cout << ((long long)dp[num][1] + dp[num][2] + dp[num][3]) % MOD << "\n";
    }
}