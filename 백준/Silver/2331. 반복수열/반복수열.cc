#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000000 

int visited[MAX] = {0, };
int P;                       

void dfs(int x) {         
    
    if (visited[x] == 2) return;  
    
    visited[x]++;                    

    int sum = 0;
    
    while (x != 0) {
        sum += pow(x % 10, P);
        x /= 10;
    }

    dfs(sum);
}

int main() {
    int N;
    cin >> N >> P;

    dfs(N);
    
    int cnt = 0;
    
    for (int i=0; i < MAX; i++) {
        if (visited[i] == 1)
            cnt++;
    }
    
    cout << cnt;
}