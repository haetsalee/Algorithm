#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B;
vector<int> arr[101];
int visited[101] = { 0, };

void dfs(int now)
{
	if (now == B) 
		return;

	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];

		if (visited[next] == 0) {
			visited[next] = visited[now] + 1;
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> A >> B;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int parent, child;
		cin >> parent >> child;
		arr[parent].push_back(child);
		arr[child].push_back(parent);
	}

	dfs(A);

	if (visited[B] == 0)
		cout << -1;
	else
		cout << visited[B];

	return 0;
}