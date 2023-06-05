#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
char arr[21][21] = { 0, };
int visited[26];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int result = 0;

void dfs(int x, int y, int cnt)
{
	result = max(result, cnt);

	for (int k = 0; k < 4; k++) {
		int nx, ny;
		nx = x + dx[k];
		ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M ) continue;

		int next = (int)arr[nx][ny] - 65;
		if (visited[next] == 0)
		{
			visited[next] = 1;
			dfs(nx, ny, cnt + 1);
			visited[next] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int start = (int)arr[0][0] - 65;
	visited[start] = 1;
	dfs(0, 0, 1);

	cout << result;
}