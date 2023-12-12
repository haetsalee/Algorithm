#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minScore = 987654321, maxScore = 0;

void dfs(int num, int cnt) {
    // 홀수를 카운트
    int tempNum = num;
    while (tempNum > 0) {
        if ((tempNum % 10) % 2 == 1) cnt++;
        tempNum /= 10;
    }

    // 1. 수가 한 자리이면 값 구한뒤 종료
    if (num < 10) {
        minScore = min(minScore, cnt);
        maxScore = max(maxScore, cnt);
    }

    // 2. 수가 두 자리이면 두 수를 합해서 재귀함수 호출
    else if (num < 100) {
        int newNum = num / 10 + num % 10;
        dfs(newNum, cnt);
    }

    // 3. 수가 세자리 이상일 때
    else {
        // 자리수로 나누기 위해 문자열로 변환
        string strNum = to_string(num);

        for (int i = 1; i < strNum.length() - 1; i++) {
            for (int j = i + 1; j < strNum.length(); j++) {
                string s1 = strNum.substr(0, i);
                string s2 = strNum.substr(i, j - i);
                string s3 = strNum.substr(j);

                int newNum = stoi(s1) + stoi(s2) + stoi(s3);
                dfs(newNum, cnt);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    dfs(N, 0);

    cout << minScore << " " << maxScore << "\n";
    return 0;
}
