#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, V;
int arr[1001][1001] = { 0, };
int visited[1001] = { 0, };
queue<int> q;

void dfs(int now) 
{
	visited[now] = 1;
	cout << now << " ";

	for (int next = 1; next <= N; next++) {
		if (arr[now][next] == 0 || visited[next] == 1) continue;
		dfs(next);
	}
}

void bfs(int now)
{
	int visited[1001] = { 0, };

	q.push(now);
	visited[now] = 1;
	
	while (!q.empty())
	{
		now = q.front();
		q.pop();

		cout << now << " ";

		for (int next = 1; next <= N; next++) {
			if (arr[now][next] == 0 || visited[next]) continue;
			
			visited[next] = 1;
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	dfs(V);
	cout << "\n";
	bfs(V);
}