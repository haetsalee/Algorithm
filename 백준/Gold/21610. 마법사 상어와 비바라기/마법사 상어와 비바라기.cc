#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 크기가 N*N인 격자
#define MAX_N 51

int N, M;
int arr[MAX_N][MAX_N];	// arr[r][c]는 (r,c)에 있는 바구니에 있는 물의 양
int cloud[MAX_N][MAX_N]; // 구름 있었던 곳 방문 체크

// 구름의 좌표룰 담을 구조체와 vector 생성
struct Pos {
	int x, y;
};

vector<Pos> clouds;
//vector<Pos> addWater;

// 구름을 움직일 8방향 (←, ↖, ↑, ↗, →, ↘, ↓, ↙)
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void bibaragi() {
	// (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름
	for (int i = N - 1; i <= N; i++) {
		for (int j = 1; j <= 2; j++) {
			clouds.push_back({ i, j });
		}
	}
}

void moveCloud(int dir, int dis) {
	for (int i = 0; i < clouds.size(); i++) {
		Pos& now = clouds[i];

		// 이동하려는 길이 자체가 N보다 클 경우에
		dis %= N;

		int nx = now.x + dx[dir] * dis;
		int ny = now.y + dy[dir] * dis;

		// 0행과 N행, 0열과 N열이 연결되어 있기 때문에
		// 이동한 곳이 0보다 작거나 N과 같거나 크다면 범위 재설정
		
		if (nx < 1) {
			nx += N;
		}
		else if (nx > N) {
			nx -= N;
		}

		if (ny < 1) {
			ny += N;
		}
		else if (ny > N) {
			ny -= N;
		}

		// 이동한 위치에 비구름 생성 후 구름 위치 업데이트
		now.x = nx, now.y = ny;

		// 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니 물 += 1
		arr[nx][ny] += 1;
		
		// 3. 구름 다 사라짐 -> 3번에서 구름이 사라진 칸은 구름 안생김!!
		// -1로 방문 체크
		cloud[nx][ny] = -1;
	}
}

void waterCopyBug() {
	// 물이 증가한 곳 중에서
	for (int i = 0; i < clouds.size(); i++) {
		// 대각선 거리가 1인 칸에 물있는 바구니 카운트
		int cntBasket = 0;

		int x = clouds[i].x;
		int y = clouds[i].y;

		for (int j = 1; j < 9; j++) {
			// 홀수인 경우 상하좌우라서 넘어감
			if (j % 2) continue;

			int nx = x + dx[j];
			int ny = y + dy[j];

			// N * N격자 안에서만 범위체크, 경계 넘어가면 거리 1 아님
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

			if (arr[nx][ny] > 0)
				cntBasket++;
		}

		// 물이 있는 바구니 수만큼(r, c) 물의 양 증가
		arr[x][y] += cntBasket;
	}
}

void makeCloud() {
	// 벡터 초기화
	clouds.clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 바구니에 저장된 물의 양이 2 이상이면 모든 칸에 구름 생기고 물의 양 - 2
			if (arr[i][j] >= 2) {
				// -> 3번에서 구름이 사라진 칸은 구름 안생김!!
				if (cloud[i][j] == -1) continue;

				arr[i][j] -= 2;

				clouds.push_back({ i, j });
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	// 비바라기 시전
	bibaragi();

	// 이후 구름에 M번 이동을 명령!
	while (M--) {
		int dir, dis;
		cin >> dir >> dis;

		// 구름 방문체크 초기화
		memset(cloud, 0, sizeof(cloud));

		// 1. 모든 구름은 di 방향으로 si칸 이동
		moveCloud(dir, dis);

		// 모든 구름의 이동과 물 증가가 끝난 후
		// 4. 2에서 물이 증가한 칸(r,c)에 물복사버그 마법 시전
		waterCopyBug();
		
		// 5. 구름 만들기
		makeCloud();
	}
	
	// 전체 물의 양
	int totalWater = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			totalWater += arr[i][j];
		}
	}

	cout << totalWater;
}