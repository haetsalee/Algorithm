#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int R, C, T;
pair<int, int> cleaner[2];

#define MAX 51
int arr[MAX][MAX];
int copyArr[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void spreadDust() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == -1 || arr[i][j] == 0) continue;

			int value = arr[i][j] / 5;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || arr[nx][ny] == -1) continue;
				
				copyArr[nx][ny] += value;
				cnt++;
			}
			copyArr[i][j] -= (cnt * value);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] += copyArr[i][j];
			copyArr[i][j] = 0;
		}
	}
}

void workCleaner() {
	// 위쪽 공기청정기 작동 (반시계방향 순환)
	for (int i = cleaner[0].first - 1; i > 0; i--)
		arr[i][0] = arr[i - 1][0];
	for (int i = 0; i < C - 1; i++) 
		arr[0][i] = arr[0][i + 1];
	for (int i = 0; i < cleaner[0].first; i++) 
		arr[i][C - 1] = arr[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--) 
		arr[cleaner[0].first][i] = arr[cleaner[0].first][i - 1];

	arr[cleaner[0].first][1] = 0;

	// 아래쪽 공기청정기 작동 (시계방향 순환)
	for (int i = cleaner[1].first + 1; i < R - 1; i++) 
		arr[i][0] = arr[i + 1][0];
	for (int i = 0; i < C - 1; i++) 
		arr[R - 1][i] = arr[R - 1][i + 1];
	for (int i = R - 1; i > cleaner[1].first; i--) 
		arr[i][C - 1] = arr[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--) 
		arr[cleaner[1].first][i] = arr[cleaner[1].first][i - 1];

	arr[cleaner[1].first][1] = 0;
}

int countDust() {
	int total = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0) 
				total += arr[i][j];
		}
	}
	return total;
}

int main() {
	cin >> R >> C >> T;
	int cleanerIdx = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				cleaner[cleanerIdx++] = { i, j };
			}
		}
	}

	while (T--) {
		spreadDust();
		workCleaner();
	}

	cout << countDust();
}