#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, coke, sprite;
	cin >> A >> B >> C >> coke >> sprite;

	int minB = min({ A, B, C });
	int minD = min(coke, sprite);
	int total = minB + minD - 50;
	cout << total;
}