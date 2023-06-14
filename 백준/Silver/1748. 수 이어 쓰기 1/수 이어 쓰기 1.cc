#include<iostream>
using namespace std;

int main(void) {

	int N;
	int cnt = 0;

	cin >> N;

	if (N < 10) {
		cnt = N;
	}
	else {
		for (int i = 1; i <= N; i *= 10) {
			cnt += N - i + 1;
		}
	}
	
	cout << cnt;
}