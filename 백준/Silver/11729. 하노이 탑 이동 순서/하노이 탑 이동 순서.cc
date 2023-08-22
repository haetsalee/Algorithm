#include <iostream>
using namespace std;

void solve(int N, int s, int m, int e) 
{
    if (N == 1)
        cout << s << " " << e << "\n";
    else {
        solve(N - 1, s, e, m);
        cout << s << " " << e << "\n";
        solve(N - 1, m, s, e);
    }
}

int check(int n) 
{
    if (n == 1)
        return 1;
    return 2 * check(n-1) + 1;
}

int main() 
{
    int N;
    cin >> N;
    cout << check(N) << "\n";
    solve(N, 1, 2, 3);
}