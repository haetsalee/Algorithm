#include <iostream>
#include <set>
using namespace std;

int N;
int num[4] = { 1, 5, 10, 50 };
set<int> s;

void dfs(int idx, int cnt, int sum) {
    if (cnt == N) {
        s.insert(sum);
        return;
    }

    for (int i = idx; i < 4; i++) {
        dfs(i, cnt + 1, sum + num[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    dfs(0, 0, 0);

    cout << s.size();

    return 0;
}
