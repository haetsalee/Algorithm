#include <iostream>
using namespace std;

int solve(int M, int N, int x, int y) {
    while (x <= M * N) {
        if ((x-y) % N == 0) {
            return x;
        }
        x += M;
    }
    return -1;
}

int main()
{
    int T, M, N, x, y;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        cin >> M >> N >> x >> y;
        cout << solve(M, N, x, y) << "\n";
    }
    
    return 0;
}