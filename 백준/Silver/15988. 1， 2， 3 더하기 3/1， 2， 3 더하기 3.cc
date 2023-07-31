#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000009; 

int main(){
	int N, num;
	cin >> N;
	
	long long dp[1000001] = {0, 1, 2, 4};
	
	while(N--) {
	    cin >> num;
	    for(int i=4; i<=num; i++) {
		    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD; 
	    }
	    
	    cout << dp[num] << "\n";
	}
}