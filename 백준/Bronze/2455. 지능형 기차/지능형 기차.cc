#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int out, in;
    int total = 0;
    int max_total = 0;
    
    for (int i = 0; i < 4; i++) {
        cin >> out >> in;
        total -= out;
        total += in;
        max_total = max(max_total, total);
    }

    cout << max_total;

    return 0;
}
