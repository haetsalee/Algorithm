#include <bits/stdc++.h>
using namespace std;

#define MAX 126

int N;
int arr[MAX][MAX] = {0, };
int dist[MAX][MAX] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs() {
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    dist[0][0] = arr[0][0];
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (0 > nx || nx >= N || 0 > ny || ny >= N) continue; 
                
            if (dist[nx][ny] > dist[x][y] + arr[nx][ny]) {
                dist[nx][ny] = dist[x][y] + arr[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    
    return dist[N-1][N-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cnt = 1;
	
	while (true) {
	    cin >> N;
	    if (N == 0) break;
	    
	    for (int i=0; i<N; i++) {
	        for (int j=0; j<N; j++) {
	            cin >> arr[i][j];
	            dist[i][j] = 987654321;
	        }
	    }
	    
	    cout << "Problem " << cnt++ << ": " << bfs() << "\n";
	}
}
