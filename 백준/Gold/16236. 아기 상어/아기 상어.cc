#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 21
int arr[MAX][MAX];
int visited[MAX][MAX];

int N, sx, sy;

int sharkSize = 2;
int eatCnt = 0;
int totalTime = 0;

struct Node {
	int x, y, time;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<Node> fish;

bool compare(Node a, Node b) {
	if (a.time == b.time) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.time < b.time;
}

void bfs(int x, int y) {
	queue<Node> q;
	q.push({ x, y, 0 });
	visited[x][y] = 1;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (arr[cur.x][cur.y] > 0 && arr[cur.x][cur.y] < sharkSize) {
			fish.push_back({ cur.x, cur.y, cur.time });
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
			if (arr[nx][ny] > sharkSize) continue;

			visited[nx][ny] = 1;
			q.push({ nx, ny, cur.time + 1 });
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i, sy = j;
				arr[i][j] = 0;
			}
		}
	}

	while (true) {
		fish.clear();
		memset(visited, 0, sizeof(visited));
		bfs(sx, sy);

		if (fish.empty()) break;

		sort(fish.begin(), fish.end(), compare);
		totalTime += fish[0].time;
		eatCnt++;
		if (eatCnt == sharkSize) {
			sharkSize++;
			eatCnt = 0;
		}
		arr[fish[0].x][fish[0].y] = 0;
		sx = fish[0].x, sy = fish[0].y;
	}

	cout << totalTime;

	return 0;
}