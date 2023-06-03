#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int arr[101][101] = { 0, };
int visited[101][101] = { 0, };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt;

vector<int> result;

void dfs(int x, int y) {
	int nx, ny;

	visited[x][y] = true;
	cnt++;

	for (int k = 0; k < 4; k++) {
		nx = x + dx[k];
		ny = y + dy[k];

		if (nx >= 0 && ny >= 0 && nx < M && ny < N && visited[nx][ny]==0) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				arr[y][x] = 1;
				visited[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && visited[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());

	int size = result.size();
	cout << size << "\n";

	for (int i = 0; i < size; i++) {
		cout << result[i] << " ";
	}

	return 0;
}