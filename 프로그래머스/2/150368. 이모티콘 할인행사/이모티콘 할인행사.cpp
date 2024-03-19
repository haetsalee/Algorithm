#include <iostream>
#include <vector>
using namespace std;

int maxCnt = 0, maxPrice = 0; // 최대 가입자 수, 최대 매출
vector<int> sales; // 적용된 할인율
int salePer[4] = {10, 20, 30, 40}; // 할인율 옵션

void dfs(vector<vector<int>>& users, vector<int>& emoticons, int idx = 0) {
    if(idx == emoticons.size()) {
        int curCnt = 0, curPrice = 0;
        
        for(auto& user : users) {
            int userPrice = 0;
            
            for(int j = 0; j < emoticons.size(); j++) {
                if(user[0] <= sales[j]) {
                    userPrice += emoticons[j] * (100 - sales[j]) / 100;
                }
            }
            
            if(userPrice >= user[1]) curCnt++;
            else curPrice += userPrice;
        }
        
        if(maxCnt < curCnt || (maxCnt == curCnt && maxPrice < curPrice)) {
            maxCnt = curCnt;
            maxPrice = curPrice;
        }
        return;
    }
    
    for(int i = 0; i < 4; ++i) {
        sales.push_back(salePer[i]);
        dfs(users, emoticons, idx + 1);
        sales.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(users, emoticons);
    
    answer.push_back(maxCnt);
    answer.push_back(maxPrice);
    
    return answer;
}