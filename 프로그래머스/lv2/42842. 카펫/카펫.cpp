#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    for (int i=yellow; i>0; i--) {
        if (yellow % i == 0) {
            int x = i + 2;
            int y = yellow / i + 2;
            
            if (((x+y) * 2 - 4) == brown) {
                answer[0] = x;
                answer[1] = y;
                break;
            }
        }
    }
    return answer;
}