#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[1001];
bool visited[1001];

void dfs(int now) {
	visited[now] = true;
	
	for (int i=0; i<v[now].size(); i++) {
		int next = v[now][i];
		
		if (!visited[next])
			dfs(next);
	}
}

int main() 
{
	int T;
	cin >> T;
	
	while (T--) {
		int N;
		cin >> N;
		
		for (int i=1; i<=N; i++) {
			v[i].clear();
			visited[i]=false;
		}
		
		for (int i=1; i<=N; i++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}
		
		int cnt = 0;
		for (int i=1; i<=N; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
		
		cout << cnt << "\n";
	}
}