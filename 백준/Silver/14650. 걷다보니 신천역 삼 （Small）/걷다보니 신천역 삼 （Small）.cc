#include <iostream>
using namespace std;

int dp[10][3];

int main() 
{
    int N;
    cin >> N;
    
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    
    for (int i=2; i<=N; i++) {
        for (int j=0; j<3; j++) {
            dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        }
    }
    
    cout << dp[N][0];
    
    return 0;
}