#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	if (A == B && B == C)
		cout << 10000 + A * 1000;
	else if (A == B || B == C)
		cout << 1000 + B * 100;
	else if (A == C)
		cout << 1000 + A * 100;
	else
		cout << max(max(A, B), C) * 100;

	return 0;
}