#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T, M, N, K;
int arr[50][50] = { 0, };
int visited[50][50] = { 0, };

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

struct Node {
	int x;
	int y;
};

void bfs(int x, int y) {
	queue<Node> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int k=0; k<4; k++) {
		    int nx, ny;
			nx = now.x + dx[k];
			ny = now.y + dy[k];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (arr[nx][ny] == 0 || visited[nx][ny] == 1) continue;
			
			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	cin >> T;

	for (int tc=0; tc<T; tc++) {
	    memset(arr, 0, sizeof(arr));
	    memset(visited, 0, sizeof(visited));
	    
		cin >> M >> N >> K;
    
		for (int i=0; i<K; i++) {
			int m, n;
			cin >> m >> n;
			arr[n][m] = 1;
		}

		int cnt = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (arr[i][j] == 1 && visited[i][j] == 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		
		cout << cnt << "\n";
	}
}