#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i=0; i<N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int result = -1;

    for (int i=N-1; i>1; i--) {
        if (v[i] < v[i - 1] + v[i - 2]) {
            result = v[i] + v[i - 1] + v[i - 2];
            break;
        }
    }

    cout << result << "\n";
}