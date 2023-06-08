#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxN = 8;
int N, M;
int arr[maxN][maxN] = { 0, };
int visited[maxN][maxN] = { 0, };
int maxCnt = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct Node {
	int x;
	int y;
};

void bfs()
{
	int temp[maxN][maxN];
	queue<Node> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = arr[i][j];
			if (temp[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx, ny;
			nx = now.x + dx[k];
			ny = now.y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (temp[nx][ny] == 2 || temp[nx][ny] == 1) continue;

			temp[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	
	maxCnt = max(cnt, maxCnt);
}


void wall(int cnt)
{
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				memset(visited, 0, sizeof(visited));
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}
		}
	}

	cout << maxCnt;
}