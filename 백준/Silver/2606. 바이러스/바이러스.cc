#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[101][101] = {0, };
int visited[101] = {0, };
int cnt;

void dfs(int now)
{
    visited[now] = 1;
    
    for (int next=1; next<=N; next++) {
        if (arr[now][next] == 0 || visited[next]==1) continue;
        
        cnt++;
        dfs(next);
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int from, to;
        cin >> from >> to;
        arr[from][to] = 1;
        arr[to][from] = 1;
    }
    
    cnt = 0;
    dfs(1);
    cout << cnt;
}