#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 물고기의 위치, 방향, 생사 상태를 저장
struct Fish {
	int x, y, dir;
	bool dead;
};

Fish fish[17];  // 각 물고기에 대한 정보를 저장하는 배열
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; 
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int map[4][4];  // 맵 정보를 저장하는 배열
int ans;  // 결과값을 저장하는 변수

// 맵 정보와 물고기 정보를 복사하는 함수
void copy_state(int a[4][4], int b[4][4], Fish* c, Fish* d) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = b[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) {
		c[i] = d[i];
	}
}

// 물고기를 이동시키는 함수
void move_fish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].dead) continue;  // 죽은 물고기는 이동 X

		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;  // 물고기의 현재 방향

		// 물고기가 이동할 수 있는 방향을 찾는 반복문
		for (int j = 0; j < 8; j++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 이동할 위치가 범위 안이고, 상어(-1)가 없는 경우
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && map[nx][ny] != -1) {
				swap(map[nx][ny], map[x][y]);  // 현재 물고기와 다른 물고기 위치 변경
				fish[i] = { nx, ny, dir, false };  // 현재 물고기 정보 업데이트

				if (map[x][y] != -1) {  // 변경된 위치에 물고기가 있었다면 그 물고기 정보도 업데이트
					fish[map[x][y]] = { x, y, fish[map[x][y]].dir, false };
				}

				break;
			}

			else {
				dir = (dir + 1) % 8;  // 이동할 수 없다면 방향을 바꿈
			}
		}
	}
}

void dfs (int shark_x, int shark_y, int sum) {
	// 최대 점수 갱신
	ans = max(ans, sum);

	// 백업
	Fish temp_fish[17];
	int temp_map[4][4];
	copy_state(temp_map, map, temp_fish, fish);

	// 상어 현재 위치의 물고기를 먹음
	int dir = fish[map[shark_x][shark_y]].dir;
	fish[map[shark_x][shark_y]].dead = true;
	map[shark_x][shark_y] = -1;

	// 물고기 이동
	move_fish();

	// 상어가 이동할 수 있는 모든 위치로 이동
	for (int i = 1; i <= 3; i++) {
		int nx = shark_x + dx[dir] * i;
		int ny = shark_y + dy[dir] * i;

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;

		if (map[nx][ny] == 0) continue;  // 물고기가 없는 위치로는 이동 X

		map[shark_x][shark_y] = 0;

		dfs(nx, ny, sum + map[nx][ny]);  // 새로운 위치에서 다시 탐색

		map[shark_x][shark_y] = -1;  // 복구
	}

	// 상태 복구
	copy_state(map, temp_map, fish, temp_fish);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			fish[num] = { i, j, dir - 1, false };
			map[i][j] = num;
		}
	}

	dfs(0, 0, map[0][0]);

	cout << ans;

	return 0;
}
