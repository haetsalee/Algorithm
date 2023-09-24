#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    string arr[N];
    int max_value = 1;
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
        
    for (int i=0; i<N-1; i++){
        for (int j=0; j<M-1; j++){
            for(int k=1; k<min(N, M); k++){
                if (i+k < N && j+k < M) {
                    char temp = arr[i][j];
                    
                    if (arr[i][j+k] == temp && arr[i+k][j] == temp && arr[i+k][j+k] == temp)
                        max_value = max(max_value,(k+1)*(k+1));
                }
            }
        }
    }
    
    cout << max_value;
}