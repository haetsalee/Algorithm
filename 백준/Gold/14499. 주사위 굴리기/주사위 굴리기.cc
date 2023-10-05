#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, k;
int arr[21][21];

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int dice[7] = { 0, };

void rotate (int n) {
    int temp[7];
    for (int i = 0; i < 7; i++) temp[i] = dice[i];
    
	if (n == 1) {
		dice[1] = temp[4];
		dice[4] = temp[6];
		dice[6] = temp[3];
		dice[3] = temp[1];
	}
	
	else if (n == 2) {
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[6] = temp[4];
		dice[4] = temp[1];
	}
	
	else if (n == 3) {
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	
	else if (n == 4) {
	    dice[1] = temp[2];
	    dice[2] = temp[6];
	    dice[6] = temp[5];
		dice[5] = temp[1];
	}
}

void move(int k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
    
    rotate(k); 

    if (arr[nx][ny] == 0) 
		arr[nx][ny] = dice[6];
		
	else {
		dice[6] = arr[nx][ny];
		arr[nx][ny] = 0;
	}
		
	cout << dice[1] << "\n";
		
	x = nx;
	y = ny;    
}

int main()
{
    cin >> N >> M >> x >> y >> k;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0; i<k; i++) {
        int order; cin >> order;
        move(order);
    }
}
