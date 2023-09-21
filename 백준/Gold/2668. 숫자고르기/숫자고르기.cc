#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int arr[MAX] = {0, };
int visited[MAX] = {0, };
vector<int> result;

void dfs(int start, int now) {
    if (visited[now]) {
        if (start == now) 
            result.push_back(now);
        return;
    }
    
    
    visited[now] = 1;
    dfs(start, arr[now]);
}

int main()
{
    int N; cin >> N;
    
    for (int i=1; i<=N; i++)
        cin >> arr[i];
    
    for (int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }
    
    cout << result.size() << "\n";
    
    for (int i=0; i<result.size(); i++)
        cout << result[i] << "\n";
}