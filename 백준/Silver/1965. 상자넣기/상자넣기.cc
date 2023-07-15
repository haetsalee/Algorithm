#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = {0, };
int dp[1001] = {0, };

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    fill(dp, dp+N, 1);
    
    int result = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result;
}
