#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
	cin >> N;
	
	int arr[1001] = {0, };
    int dp[1001] = {0, };
    
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++) 
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
	}
	
	cout << dp[N];
}