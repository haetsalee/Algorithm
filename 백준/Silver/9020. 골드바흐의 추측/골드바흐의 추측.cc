#include <iostream>
using namespace std;

int main() {
	int T, N;
	bool num[10001];
	
	fill(num, num + 10000, true);
	num[1] = false;
	
	for (int i = 2; i * i < 10001; i++) {
		if (num[i]) {
			for (int j = i * i; j < 10001; j += i) {
				num[j] = false;
			}
		}
	}
	
	cin >> T;
	
	while (T--) {
		cin >> N;
		for (int i = N / 2; i > 0; i--) {
			if (num[i] && num[N - i]) {
				cout << i << " " << N-i << "\n";
				break;
			}
		}
	}
	
	return 0;
}