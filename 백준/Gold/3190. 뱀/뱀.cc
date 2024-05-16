#include <iostream>
#include <queue>

using namespace std;

int arr[101][101] = { 0, };		// NxN 정사각 보드위
int N, K, L;	// 보드의 크기, 사과의 개수, 뱀의 방향 전환 횟수

int snakeDir = 0;	// 뱀은 처음에 오른쪽방향
int moveInfo[10001] = { 0, };
queue<pair<int, int>> snakeBody;

int turn = 0;

int headX = 1, headY = 1;	// 초기 머리의 위치
bool gameStop = false;

// →, ↓, ←, ↑ 방향 
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool checkRange(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > N) {
		return false;
	}
	return true;
}

void moveSnake() {
	headX += dx[snakeDir];
	headY += dy[snakeDir];
	snakeBody.push({ headX, headY });

	// 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝
	if (!checkRange(headX, headY) || arr[headX][headY] == 9) {
		gameStop = true;
	}

	// 이동한 칸 사과 체크
	else {
		// 사과X -> 몸길이를 줄여서 꼬리가 위치한 칸 지움
		if (arr[headX][headY] != -1) {
			auto tail = snakeBody.front();
			snakeBody.pop(); // 꼬리 위치 제거
			arr[tail.first][tail.second] = 0; // 보드에서 꼬리 제거
		}

		// 사과O -> 그 칸의 사과먹기
		arr[headX][headY] = 9;
	}
}

void changeDir() {
	// 게임 시작 시간으로부터 X초가 끝난 뒤
	// 왼쪽(L) 또는 오른쪽(D)로 90도 방향을 회전
	if (moveInfo[turn] != 0) {
		snakeDir = (snakeDir + moveInfo[turn] + 4) % 4;
	}
}

int main() {
	cin >> N >> K;

	// 게임이 시작할때 뱀은 맨위 맨좌측에 위치
	arr[1][1] = 9;

	// 초기 머리의 위치 저장
	snakeBody.push({ 1, 1 });

	// 사과의 위치 표시
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = -1;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int num;
		char dir;
		cin >> num >> dir;

		// D일때 시계방향 L일때 반시계방향
		if (dir == 'D') moveInfo[num] = 1;	
		else moveInfo[num] = -1;
	}

	while (!gameStop) {
		// turn 증가
		turn++;

		// 1. 뱀은 몸길이를 늘려 머리를 다음칸에 위치
		moveSnake();

		// 2. 방향 전환
		changeDir();
	}

	cout << turn << "\n";
}