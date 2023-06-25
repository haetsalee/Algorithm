#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	int min_value = 50;
	for (int i = 0; i < B.size(); i++) {
		if (i + A.size() > B.size()) continue;

		int cnt = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[i + j]) 
			    cnt++;
		}
		min_value = min(cnt, min_value);
	}
	cout << min_value;

	return 0;
}