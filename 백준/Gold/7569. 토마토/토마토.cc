#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Dir {
	int x;
	int y;
	int z;
};

int arr[101][101][101] = { 0, };
int cnt[101][101][101] = { 0, };
queue<Dir> q;

int dx[6] = { 1,0,-1,0,0,0 };  
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int M, N, H;

void bfs() {
	while (!q.empty()) {
		Dir now = q.front();
		q.pop();

		for (int k = 0; k < 6; k++) {
			int nx = now.x + dx[k];
			int ny = now.y + dy[k];
			int nz = now.z + dz[k];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			
			if (cnt[nx][ny][nz] >= 0) continue;

			q.push({nx, ny, nz});
			cnt[nx][ny][nz] = cnt[now.x][now.y][now.z] + 1;
		}
	}
}
int main() {
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) { 
					q.push({ i, j, k });
				}
				if (arr[i][j][k] == 0) { 
					cnt[i][j][k] = -1;
				}
			}
		}
	}

	bfs();

	int result = 0;
	for (int k = 0; k < H; k++) { 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cnt[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				result = max(cnt[i][j][k], result);
			}
		}
	}
    
	cout << result << '\n';
	return 0;
}