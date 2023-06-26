#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
	int N, temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
		
	if (prev_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << ' ';
		}
	} 
	else cout << -1;
}