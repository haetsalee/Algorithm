#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> v[51];
int visited[51] = {0, };

void DFS(int now, int len){
    visited[now] = 1;
    
    if(len == 2)
        return;
    
    for (int i=0; i<v[now].size(); i++){
        DFS(v[now][i], len+1);   
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            char c;
            cin >> c;
            if(c == 'Y')
                v[i].push_back(j);
        }
    }
    
    int result = 0;
    for(int i=1; i<=N; i++){
        memset(visited, false, sizeof(visited));
        
        int cnt = 0;
        DFS(i, 0);
        
        for(int i=1; i<=N; i++){
            if(visited[i] == 1)
                cnt++;
        }
        
        result = max(result, cnt);
    }
    
    cout << result - 1 << "\n";
}
