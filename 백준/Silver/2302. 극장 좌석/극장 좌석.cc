#include <iostream>
using namespace std;

#define MAX 41

int dp[MAX];
int vip[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
        
    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<MAX; i++)
        dp[i] = dp[i-1] + dp[i-2];
 
    int result = 1;
    
    for (int i=1; i<=M; i++) {
        cin >> vip[i];
        result *= dp[vip[i] - vip[i-1] - 1];
    }
    
    result *= dp[N - vip[M]];
    
    cout << result;
}