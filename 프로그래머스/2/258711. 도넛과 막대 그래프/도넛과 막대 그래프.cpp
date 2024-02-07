#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Cnt {
    int giveCnt = 0;    // 다른 정점에 간선을 주는 횟수
    int receiveCnt = 0; // 간선을 받는 횟수
};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    unordered_map<int, Cnt> dict;   // key: 정점, value: 해당 정점 값
    int maxNum = 0;

    // 모든 간선 순회
    for (auto& edge : edges) {
        int giveNum = edge[0];      // 시작 정점
        int receiveNum = edge[1];   // 끝 정점

        maxNum = max(maxNum, max(giveNum, receiveNum));

        // 정점에 대한 정보 생성 후 초기화
        if (dict.find(giveNum) == dict.end()) {
            dict[giveNum] = Cnt();
        }
        
        if (dict.find(receiveNum) == dict.end()) {
            dict[receiveNum] = Cnt();
        }
        
        // 업데이트
        dict[giveNum].giveCnt++;
        dict[receiveNum].receiveCnt++;
    }

    // 정점 순회하며 각 정점의 유형 판단!
    for (int i = 1; i <= maxNum; i++) {
        int receiveCnt = dict[i].receiveCnt;
        int giveCnt = dict[i].giveCnt;

        if (receiveCnt == 0 && giveCnt >= 2) {
            answer[0] = i;
        } 
        
        // 막대 모양 그래프
        else if (giveCnt == 0) {
            answer[2]++;
        } 
        
        // 8자 그래프
        else if (receiveCnt >= 2 && giveCnt >= 2) {
            answer[3]++;
        }
    }
    
    // 도넛 모양 그래프 = 전체 - 나머지 그래프
    answer[1] = dict[answer[0]].giveCnt - answer[2] - answer[3];
    
    return answer;
}
