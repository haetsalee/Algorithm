#include <iostream>
using namespace std;

int dp[1000001] = {0, };
int arr[1000001] = {0, };

int main() {
	int N;
	cin >> N;
	
	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i-1] + 1;
		arr[i] = i-1 ;
		
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			arr[i] = i / 2;
		}
		
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			arr[i] = i / 3;
		}
	}
	
	cout << dp[N] << "\n";
	
	int temp = N;
	
	while (true) {
		cout << temp << " ";
		if (temp == 1) break;
		
		temp = arr[temp];
	}
	
	return 0;
}