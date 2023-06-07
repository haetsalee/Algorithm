#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int F, S, G, U, D;
int visited[1000001];
int result = 0;
vector<int> dx;
queue<int> q;
void bfs(int now)
{
	visited[now] = 1;
	q.push(now);

	while (!q.empty())
	{
		now = q.front();
		q.pop();

		for (int k = 0; k < 2; k++) {
			int next = now + dx[k];

			if (0 < next && next <= F && visited[next] == 0) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> F >> S >> G >> U >> D;
	dx.push_back(U);
	dx.push_back(D * -1);

	bfs(S);

	if (visited[G])
		cout << visited[G] - 1;
	else
		cout << "use the stairs";

	return 0;
}