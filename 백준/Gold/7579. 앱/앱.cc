#include<iostream>
#include<algorithm>
using namespace std;

int bite[101], cost[101];
int dp[10001] = { 0, };

int main()
{
    int N, M;
	cin >> N >> M;

	for (int i=0; i<N; i++)
	    cin >> bite[i];
	
    int total = 0;
	for(int i=0; i<N; i++) {
	    cin >> cost[i];
	    total += cost[i];
	}
	
	for (int i=0; i<N; i++) {
		for (int j=total; j>=cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + bite[i]);
		}
	}

    for (int i=0; i<=total; i++) {
        if (dp[i] >= M) {
            cout << i;
            break;
        }
    }
}