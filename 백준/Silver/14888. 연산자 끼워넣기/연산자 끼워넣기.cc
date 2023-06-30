#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[12] = { 0, };
int oper[4];
int maxValue = -1000000000, minValue = 1000000000;

void dfs(int total, int cnt)
{
	if (cnt == N - 1) {
		maxValue = max(maxValue, total);
		minValue = min(minValue, total);
	}
	else {
		if (oper[0] > 0) {
			oper[0] -= 1;
			dfs(total + arr[cnt + 1], cnt + 1);
			oper[0]++;
		}

		if (oper[1] > 0) {
			oper[1] -= 1;
			dfs(total - arr[cnt + 1], cnt + 1);
			oper[1]++;
		}

		if (oper[2] > 0) {
			oper[2] -= 1;
			dfs(total * arr[cnt + 1], cnt + 1);
			oper[2]++;
		}

		if (oper[3] > 0) {
			oper[3] -= 1;
			dfs(total / arr[cnt + 1], cnt + 1);
			oper[3]++;
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	dfs(arr[0], 0);

	cout << maxValue << "\n" << minValue;

}