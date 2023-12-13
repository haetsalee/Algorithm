#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

// 덧셈, 뺄셈, 곱셈, 나눗셈 순서
vector<int> op(4);  
int maxi = -1000000001;
int mini = 1000000001;

// 모든 조합을 탐색하고 결과값을 계산
void dfs(int idx, int sum) {
    // 모든 수에 대한 계산이 끝났으면
    if (idx == N) {
        // 최대값과 최소값을 갱신
        maxi = max(maxi, sum);
        mini = min(mini, sum);
        return;
    }

    // 각 연산자에 대해 남아있는 경우에만 해당 연산을 수행하고 다음 수로 넘어감
    // 연산자의 개수를 하나 줄였다가 재귀 호출이 끝나면 다시 늘려줌
    if (op[0] > 0) {  // 덧셈
        op[0]--;
        dfs(idx + 1, sum + v[idx]);
        op[0]++;
    }

    if (op[1] > 0) {  // 뺄셈
        op[1]--;
        dfs(idx + 1, sum - v[idx]);
        op[1]++;
    }

    if (op[2] > 0) {  // 곱셈
        op[2]--;
        dfs(idx + 1, sum * v[idx]);
        op[2]++;
    }

    if (op[3] > 0) {  // 나눗셈
        op[3]--;
        dfs(idx + 1, sum / v[idx]);
        op[3]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    // 첫 번째 수와 인덱스를 인자로 dfs함수 호출
    dfs(1, v[0]);

    cout << maxi << "\n" << mini;

    return 0;
}