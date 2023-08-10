#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[16][16];
int cnt = 0;

struct Node {
	int x;
	int y;
};

void dfs(int now) {
    vector<Node> v;
    
    if(now == N){        
        cnt++;
        return;
    }
    
    for(int i=0; i<N; i++) {
        if(arr[now][i] ==0) {
            for(int j=1; j<N-now; j++) {
                if(arr[now+j][i]==0) {
                    arr[now+j][i] = 1;
                    v.push_back({now+j, i});
                }
                
                if(arr[now+j][i-j] == 0 && i-j>=0) {
                    arr[now+j][i-j] = 1;
                    v.push_back({now+j, i-j});
                }

                if(arr[now+j][i+j] == 0 && i+j < N) {
                    arr[now+j][i+j] = 1;
                    v.push_back({now+j, i+j});
                }
            }

            dfs(now+1);
            
            while(!v.empty()){
                Node now = v.back();
                v.pop_back();
                arr[now.x][now.y] = 0;
            }
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    dfs(0);
    
    cout << cnt;
}