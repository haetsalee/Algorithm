#include <iostream>
#include <vector>
using namespace std;

int N, M;
int visited[9] = {0, };
int result[9] = {0, }; 

void dfs(int x, int cnt)
{
    if (cnt == M) {
        for (int i=0; i<M; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i=x; i<=N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            result[cnt] = i;
            dfs(i+1, cnt+1);
            visited[i] = 0;
        }
    } 
}

int main()
{
    cin >> N >> M;
    dfs(1, 0);
}
