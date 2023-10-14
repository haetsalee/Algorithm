#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1500001

int dp[MAX];

int main()
{
    int N, days, money;
    cin >> N;
    
    for (int today=1; today<=N; today++) {
        cin >> days >> money;
        dp[today + days] = max(dp[today + days], dp[today] + money);
        dp[today+1] = max(dp[today], dp[today+1]);
    }
        
    cout << dp[N+1] << "\n";
}