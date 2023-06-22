#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, M;
int arr[8];
vector<int> v;
int visited[8] = { 0, };
 
void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int temp = 0;
    for (int i = idx; i < v.size(); i++) {
        if (visited[i]==0 && v[i]!=temp) {
            visited[i] = 1;
            arr[cnt] = v[i];
            temp = arr[cnt];
            dfs(i, cnt+1);
            visited[i] = 0;
        }
    }
}
 
int main() {
    cin >> N >> M;
 
    v.resize(N);
 
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
 
    sort(v.begin(), v.end());
 
    dfs(0, 0);
    return 0;
}