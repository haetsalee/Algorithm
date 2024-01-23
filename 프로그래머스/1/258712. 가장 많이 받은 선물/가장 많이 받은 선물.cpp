#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// 선물지수를 기록할 배열
int giftScore[51] = {0,};

// 주고받은 선물 기록
int giftArr[51][51] = {0};

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 친구의 이름을 인덱스로 매핑
    map<string, int> friendIndex;
    
    for (int i = 0; i < friends.size(); i++) {
        friendIndex[friends[i]] = i;
    }
    
    for (string gift : gifts) {
        stringstream ss(gift);
        string giverName, receiverName;
        ss >> giverName >> receiverName;
        
        int giver = friendIndex[giverName];
        int receiver = friendIndex[receiverName];
        
        // 주고받은 선물 배열에 저장
        giftArr[giver][receiver]++;
        
        // 선물주면 +1 받으면 -1
        giftScore[giver]++;
        giftScore[receiver]--;
    }
    
    
    vector<int> nextGifts(friends.size(), 0);
    
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {

            // 같은 사람이면 
            if (i == j) continue;

            // 친구 i가 j에게 준 선물이 더 많은 경우
            if (giftArr[i][j] > giftArr[j][i]) {
                nextGifts[i]++;
            }

            // 선물의 수가 같다면 선물 지수가 높은 경우
            else if (giftArr[i][j] == giftArr[j][i] && giftScore[i] > giftScore[j]) {
                nextGifts[i]++;
            }
        }
    }
    
    answer = *max_element(nextGifts.begin(), nextGifts.end());
    
    return answer;
}