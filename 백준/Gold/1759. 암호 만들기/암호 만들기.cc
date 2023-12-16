#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alpha;

void dfs(int idx, string password, int ja, int mo) {
    if(password.size() == L) {
        if(ja >= 2 && mo >= 1)
            cout << password << '\n';
            
        return;
    }

    for(int i = idx; i < C; i++) {
        if(alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
            dfs(i + 1, password + alpha[i], ja, mo + 1);
        else
            dfs(i + 1, password + alpha[i], ja + 1, mo);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    alpha.resize(C);
    
    for(int i = 0; i < C; i++)
        cin >> alpha[i];

    sort(alpha.begin(), alpha.end());
    
    dfs(0, "", 0, 0);

    return 0;
}