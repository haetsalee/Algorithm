#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 11

int N;
int arr[MAX][MAX];
int visited[MAX];
int result = 987654321;

void dfs(int start, int x, int cost, int cnt) {
    if (cnt == N && x == start) {
        result = min(result, cost + arr[x][start]);
        return;
    }
    
    for (int i=0; i<N; i++) {
        if (visited[i] == 0 && arr[x][i] && cost < result) {
            visited[i] = 1;
            dfs(start, i, cost + arr[x][i], cnt+1);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        dfs(i, i, 0, 0);
        memset(visited, 0, sizeof(visited));
    }
    
    cout << result;
}