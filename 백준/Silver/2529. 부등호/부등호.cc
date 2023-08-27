#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
char arr[10];
int visited[10] = {0, };
string str = "";
string min_str = "999999999";
string max_str = "-1";

void dfs(int pre, int now) {
    if (now == N + 1) {
        min_str = min(min_str, str);
        max_str = max(max_str, str);
        return;
    }
    
    if (arr[now - 1] == '>') {
        for (int i=0; i<pre; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                str += (char)(i + '0');
                dfs(i, now+1);
                visited[i] = 0;
                str.erase(now, 1);
            }
        }
    }
    
    else if (arr[now - 1] == '<') {
        for (int i=pre + 1; i<=9; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                str += (char)(i + '0');
                dfs(i, now+1);
                visited[i] = 0;
                str.erase(now, 1);
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    for (int i=0; i<=9; i++) {
        visited[i] = 1;
        str += (char)(i + '0');
        dfs(i, 1);
        visited[i] = 0;
        str.erase(0, 1);
    }
    
    cout << max_str << "\n" << min_str;
}