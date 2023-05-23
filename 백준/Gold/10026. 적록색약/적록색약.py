from collections import deque
import sys
input = sys.stdin.readline

def bfs(x, y):
    deq = deque()
    visited[x][y] = 1
    deq.append((x, y))

    while deq:
        x, y = deq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < N and arr[x][y] == arr[nx][ny] and not visited[nx][ny]:
                visited[nx][ny] = 1
                deq.append((nx, ny))


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N = int(input())
arr = [list(input()) for _ in range(N)]

visited = [[0] * N for _ in range(N)]
cnt_nor = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs(i, j)
            cnt_nor += 1

cnt_col = 0
visited = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if arr[i][j] == 'R':
            arr[i][j] = 'G'

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            bfs(i, j)
            cnt_col += 1

print(cnt_nor, cnt_col)

