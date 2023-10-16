#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int arr[MAX] = {0, };
int dp1[MAX] = {1, };
int dp2[MAX] = {1, };

int main(){
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++)
        cin >> arr[i];

    for(int i=1; i<=N; i++){
        dp1[i] = 1;
        for(int j=1; j<i; j++){
            if(arr[j] < arr[i]){
                dp1[i] = max(dp1[j]+1, dp1[i]);
            }
        }
    }

    for (int i=N; i>=1; i--){
        dp2[i] = 1;
        for (int j=N; j>i; j--){
            if(arr[j] < arr[i]){
                dp2[i] = max(dp2[j]+1, dp2[i]);
            }
        }
    }

    int result = 0;
    for (int i=1; i<=N; i++){
       int total = dp1[i] + dp2[i] - 1;
       
       if (result < total)
            result = total;
    }

    cout << result << "\n";
}