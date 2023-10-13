#include <iostream>
#include <algorithm>
using namespace std;

bool arr[246913];

void check() {
    int i = 2;
    arr[0] = false;
    arr[1] = false;

    while (i <= 246912) {
        if (arr[i])
            for (int j = i + i; j <= 246912; j += i)
                if (arr[j])
                    arr[j] = false;
        i++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    fill(arr, arr + 246913, true);
    check();
    
    while (N) {
        int cnt = 0;

        for (int i=N+1; i<=2*N; i++) {
            if (arr[i])
                cnt++;
        }
        
        cout << cnt << "\n";
        
        cin >> N;
    }
}
