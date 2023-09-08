#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = 1;
    
    while (num <= n) {
        int total = 0;
        
        for (int i=num; total<=n; i++) {
            if (total == n)
                answer++;
            
            total += i;
        }
        
        num++;
    }
    
    return answer;
}