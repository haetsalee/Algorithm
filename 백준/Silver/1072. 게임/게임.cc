#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

long long x, y;

long long binarySearch() {
    int left = 0, right = MAX;
    int z = (y * 100) / x;
	
	if (z >= 99) {
		return -1;
	}
	
	while (left <= right) {
		int mid = (left + right) / 2;
		int temp = (100 * (y + mid)) / (x + mid);
		
		if (z >= temp) 
			left = mid + 1;
		
		else 
			right = mid - 1;
	}
	
	return left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> x >> y;
	
	int result = binarySearch();
	cout << result;
}