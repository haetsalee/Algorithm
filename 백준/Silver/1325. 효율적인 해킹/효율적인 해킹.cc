#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr[10001];
int visited[100001];
int cnt;
int maxCnt = 0;
vector<int> result;

void dfs(int now)
{
	visited[now] = 1;
	cnt++;

	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];

		if (visited[next] == 1) continue;

		dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> to >> from;
		arr[from].push_back(to);
	}

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		fill_n(visited, 100001, 0);
		dfs(i);

		if (cnt > maxCnt) {
			maxCnt = cnt;
			result.clear();
			result.push_back(i);
		}
		else if (cnt == maxCnt) {
			result.push_back(i);
		}
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}