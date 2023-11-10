#include <bits/stdc++.h>
using namespace std;

#define MAX 601

int N, M, sx, sy;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    visited[sx][sy] = 1;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
            if(arr[nx][ny] == 'X' || visited[nx][ny]) continue;
            if(arr[nx][ny] == 'P')
                cnt++;
                
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            
            if (arr[i][j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }
    
    bfs();
    
    if (cnt == 0)
        cout << "TT";
    else
        cout << cnt;
}