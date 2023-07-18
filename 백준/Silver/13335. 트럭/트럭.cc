#include <iostream>
#include <queue>

using namespace std;

int N, w, l;
int weight[1000] = {0, };

int main(void)
{
    cin >> N >> w >> l;

    for (int i=0; i<N; i++) {
        cin >> weight[i];
    }
    
    queue<int> q;
    
    int now = 0;
    int time = 0;
    
    for (int i=0; i<N; i++) {
        while (1) {
            if (q.size() == w) {
                now -= q.front();
                q.pop();
            }
            
            if (weight[i] + now <= l) break;
            
            q.push(0);
            time++;
        }
        
        q.push(weight[i]);
        time++;
        now += weight[i];
    }

    cout << time + w;
    return 0;
}