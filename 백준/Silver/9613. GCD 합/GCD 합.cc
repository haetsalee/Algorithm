#include <iostream>
using namespace std;

int solve(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	return solve(y, x % y);
}

int main() {
    int T, N, num;
	long long total;
	int arr[101] = {0, };

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		total = 0;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
			for (int k = 0; k < j; k++) {
				total += solve(arr[k], arr[j]);
			}
		}

		cout << total << "\n";
	}
	return 0;
}