#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

int N, M;
int arr[MAX][MAX];
int cnt[MAX][MAX];

struct Node {
    int x, y;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
    queue<Node> q;
    q.push({ 0, 0 });
    cnt[0][0] = 0;
    
    while(!q.empty()) {
        Node now = q.front();
        q.pop();
        
        for (int k=0; k<4; k++) {
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];
            
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            
            if (arr[nx][ny] == 1) {
                if (cnt[nx][ny] > cnt[now.x][now.y] + 1) {
                    q.push({nx, ny});
                    cnt[nx][ny] = cnt[now.x][now.y] + 1;
                }
                
            }
            
            else if (arr[nx][ny] == 0) {
                if (cnt[nx][ny] > cnt[now.x][now.y]) {
                    q.push({nx, ny});
                    cnt[nx][ny] = cnt[now.x][now.y];
                }
                
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    char temp;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> temp;
            arr[i][j] = temp - '0';
            cnt[i][j] = 987654321;
        }
    }
    
    bfs();
    cout << cnt[M-1][N-1];
}