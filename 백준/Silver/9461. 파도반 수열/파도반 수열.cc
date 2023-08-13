#include <iostream>
#define MAX 101
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long long int dp[MAX] = {1, 1, 1, 2, 2};
    for (int i=5; i<MAX; i++)
        dp[i] = dp[i-1] + dp[i-5];
        
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        cout << dp[num-1] << "\n";
    }
}