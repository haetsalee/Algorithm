#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 1001

int dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string A, B;
    cin >> A >> B;

    for (int i=1; i<=A.size(); i++)
        for (int j=1; j<=B.size(); j++){
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
                
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    cout << dp[A.size()][B.size()] << "\n";
}