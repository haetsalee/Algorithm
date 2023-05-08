from collections import deque
import sys
input = sys.stdin.readline

def bfs():
    deq = deque()

    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1:
                deq.append((i, j))

    while deq:
        x, y = deq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < M and arr[nx][ny] == 0:
                arr[nx][ny] = arr[x][y] + 1
                deq.append((nx, ny))


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

M, N = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
result = 0
bfs()

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            print(-1)
            exit()
        else:
            if arr[i][j] > result:
                result = arr[i][j] - 1

print(result)