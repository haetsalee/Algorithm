#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1500001

int T[MAX], P[MAX];
int dp[MAX] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    for(int i = 1; i <= N+1; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        
        if(i + T[i] <= N+1) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }
    
    cout << dp[N+1] << "\n";
    
    return 0;
}