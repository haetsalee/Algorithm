#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
		result = max(result, dp[i]);

	cout << result;
}