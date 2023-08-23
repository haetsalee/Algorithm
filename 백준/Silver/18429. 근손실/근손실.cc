#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;
int visited[10] = {0, };

int result = 0;

void dfs(int now, int total) {
    if (total < 0) return;
    if(now == N){
        result++;
        return;
    }
    
    for(int i=0; i<N; i++){
        if(visited[i]) continue;
        
        visited[i] = 1;
        dfs(now+1, total - K + v[i]);
        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    dfs(0, 0);
    
    cout << result;
}