#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B;
int result;
vector<vector<int>> arr;
int visited[101] = { 0, };

void dfs(int now, int cnt)
{
	visited[now] = 1;

	if (now == B) 
		result = cnt;

	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];

		if (visited[next] == 1) continue;
		dfs(next, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> A >> B;
	cin >> M;
	arr.resize(N+1);
    
	for (int i = 0; i < M; i++) {
		int parent, child;
		cin >> parent >> child;
		arr[parent].push_back(child);
		arr[child].push_back(parent);
	}

	dfs(A, 0);

	if (result == 0)
		cout << -1;
	else
		cout << result;

	return 0;
}

