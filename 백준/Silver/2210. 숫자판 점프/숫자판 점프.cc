#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int arr[5][5];
set<int> s;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y, int num, int cnt) {
    if (cnt == 6) {
        s.insert(num);
        return;
    }
    
    for (int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        
        dfs(nx, ny, num * 10 + arr[nx][ny], cnt + 1);
    }
}

int main()
{
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            dfs(i, j, arr[i][j], 1);
        }
    }
    
    cout << s.size();
}