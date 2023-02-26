from collections import deque

def bfs(x, y):
    global result
    deq = deque()
    deq.append((x, y))
    arr[x][y] = 9

    while deq:
        x, y = deq.popleft()

        if x == M - 1:
            result = 'YES'
            break

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < M and 0 <= ny < N and arr[nx][ny] == 0:
                arr[nx][ny] = 9
                deq.append((nx, ny))

    return result


dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

M, N = map(int, input().split())
arr = [list(map(int, input())) for _ in range(M)]
result = 'NO'

for i in range(N):
    if arr[0][i] == 0:
        bfs(0, i)

print(result)