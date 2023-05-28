from collections import deque

def bfs(x, y):
    deq = deque()
    deq.append((x, y))
    arr_cnt[x][y] = 0

    while deq:
        x, y = deq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < M and arr[nx][ny] == 1 and arr_cnt[nx][ny] == -1:
                arr_cnt[nx][ny] = arr_cnt[x][y] + 1
                deq.append((nx, ny))

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
arr_cnt = [[-1] * M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            arr_cnt[i][j] = 0
        elif arr[i][j] == 2:
            bfs(i, j)

for cnt in arr_cnt:
    print(*cnt)