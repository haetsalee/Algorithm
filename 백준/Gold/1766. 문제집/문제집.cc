#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
#define MAX 32001

int arr[MAX];
vector<int> problem[MAX];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;
        problem[A].push_back(B);
        arr[B]++;
    }
 
    priority_queue<int> q;
 
    for (int i=1; i<=N; i++) {
        if (arr[i] == 0)
            q.push(-i);
    }
 
    while (q.empty() == 0) {
        int now = -q.top();
        q.pop();
 
        cout << now << " ";
 
        for (int i=0; i<problem[now].size(); i++) {
            int next = problem[now][i];
            arr[next]--;
            
            if (arr[next] == 0)
                q.push(-next);
        }
    }
}