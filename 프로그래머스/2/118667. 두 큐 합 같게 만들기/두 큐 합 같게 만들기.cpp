#include <string>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < queue1.size(); i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
        
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    for(int i = 0; i < 4 * queue1.size() + 1; i++){
        if(sum1 == sum2)
            return i;
        
        if(sum1 < sum2) {
            int x = q2.front();
            sum1 += x;
            sum2 -= x;
            q1.push(x);
            q2.pop();
        }
        
        else {
            int x = q1.front();
            sum2 += x;
            sum1 -= x;
            q2.push(x);
            q1.pop();            
        }
    }
    
    return -1;
}