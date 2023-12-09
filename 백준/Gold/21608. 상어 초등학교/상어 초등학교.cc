#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAX 21
// 교실 N * N 격자
int arr[MAX][MAX] = { 0, };

struct Cnt {
	int x, y, zero, like;
};

vector<Cnt> cnt;

// 학생수 N * N, 번호 1번부터 N*N번 까지 
int N;

// abs(r1 - r2) + abs(c1 - c2) = 1 을 만족하면 (r1,c1)과 (r2,c2)는 인접
// -> 상,하,좌,우 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int students[MAX*MAX+1][4];
int orderList[MAX*MAX + 1];

int result = 0;

void bfs(int x, int y, int num) {
	int tempZero = 0, tempLike = 0;
	// 한 자리마다 인접한 곳 네방향 탐색하고 빈자리와 좋아하는 학생들의 수 총합 cnt 배열에 기록
	// 지금 자리에서 네방향탐색
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		// 만약 빈자리라면 tempZero++
		if (arr[nx][ny] == 0)
			tempZero++;

		else {
			// 만약 내가 좋아하는 학생이 앉아있는 자리라면 tempLike++
			for (int i = 0; i < 4; i++) {
				if (arr[nx][ny] == students[num][i]) tempLike++;
			}
		}
	}

	// 4방향을 다 탐색하고 그 자리의 최종 결과를 Cnt에 입력함
	cnt.push_back({ x, y, tempZero, tempLike });
}

// 비교 함수
bool compare(const Cnt& a, const Cnt& b) {
	if (a.like != b.like)
		return a.like > b.like;  // 좋아하는 학생이 인접한 칸이 많은 순으로 정렬
	if (a.zero != b.zero)
		return a.zero > b.zero;  // 비어있는 칸이 많은 순으로 정렬
	if (a.x != b.x)
		return a.x < b.x;  // 행의 번호가 작은 순으로 정렬
	return a.y < b.y;  // 열의 번호가 작은 순으로 정렬
}

void Score() {
	// cnt배열을 만들어서 구할 때 마다 초기화
	cnt.clear();

	// 자리마다 좋아하는 친구수를 저장할 변수
	int likeCnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 모든 자리 탐색하고 점수 구함
			bfs(i, j, arr[i][j]);

			likeCnt = cnt.back().like;

			if (likeCnt == 4) result += 1000;
			else if (likeCnt == 3) result += 100;
			else if (likeCnt == 2) result += 10;
			else if (likeCnt == 1) result += 1;
		}
	}
}

void moveStudent(int num) {
	// arr[i][j]는 0일때 4방향 탐색해서 내가 좋아하는 학생의 번호가 있으면 + 1
	// 자리마다 cnt를 구하고 cnt가 가장 높은 곳

	// cnt배열을 만들어서 구할 때 마다 초기화
	cnt.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 0인 자리가 내가 갈 수 있는 자리
			if (arr[i][j] == 0)
				// 해당 자리의 점수를 구함
				bfs(i, j, num);
		}
	}

	// 바꿀 자리 선정
	// 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸
	// -> 비어있는 칸 상하좌우에 좋아하는 학생이 제일 많은 칸으로

	// 2. 행의 번호가 가장 작은 칸
	// 3. 열의 번호가 가장 작은 칸

	// vector를 위의 조건 대로 정렬
	// like, zero, i, j 순으로 정렬
	sort(cnt.begin(), cnt.end(), compare);
	Cnt& pick = cnt.front();

	arr[pick.x][pick.y] = num;
}

int main() {
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		int studentNum;
		cin >> studentNum;
		orderList[i] = studentNum;

		for (int j = 0; j < 4; j++) {
			cin >> students[studentNum][j];
		}
	}
	
	// 첫번째 학생은 항상 (1, 1)자리 고정
	// 같은 조건에서 가장 행의 값이 작고 열의 값이 작은 곳
	arr[1][1] = orderList[0];

	// 학생 수 만큼 자리 배치 반복
	for (int i = 1; i < N * N; i++) {
		// 학생의 번호가 들어오는 순서대로 자리를 배치 
		// orderList[i] = 학생번호 -> students의 인덱스로
		int num = orderList[i];
		moveStudent(num);
	}

	// 모든 자리배치가 완료된 후에 학생들의 만족도를 구함
	Score();

	cout << result;
	
	return 0;
}