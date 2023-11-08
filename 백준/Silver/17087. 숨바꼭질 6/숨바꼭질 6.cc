#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
 
int gcd(int x, int y) {
	if (y == 0)
		return x;
		
	else
		return gcd(y, x % y);
}
 
int main() {
	int N, S;
	cin >> N >> S;
 
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
 
	int result = abs(S - arr[0]);
	
	for (int i = 1; i < N; i++)
		result = gcd(result, abs(S - arr[i]));
 
	cout << result;
}