#include <iostream>
using namespace std;

int arr[101] = {0, };
int dp[10001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++)
	    cin >> arr[i];

	dp[0] = 1;
	
	for (int i=0; i<N; i++) {
		for (int j=arr[i]; j<=K; j++) { 
			dp[j] += dp[j-arr[i]];
		}
	}

	cout << dp[K];
}