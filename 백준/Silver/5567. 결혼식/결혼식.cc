#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[501];
int visited[501] = {0, };
int cnt = 0;
    
void bfs(int x)
{
	queue<int> q;
	visited[x] = 1;
	
	for (int i=0; i < v[x].size(); i++) {
		q.push(v[x][i]);
		visited[v[x][i]] = 1;
		cnt++;
	}
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i=0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next])
			    continue;
			    
			visited[next] = 1;
			cnt++;
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int s, e;
        cin >> s >> e;
        
        v[s].push_back(e);
        v[e].push_back(s);
    }
    
    bfs(1);
    
    cout << cnt;
}