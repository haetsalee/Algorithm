#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	vector<int> arr;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
}