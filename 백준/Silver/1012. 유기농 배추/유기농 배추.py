from collections import deque

def bfs(x, y):
    deq = deque()
    deq.append((x, y))
    visited[x][y] = 1

    while deq:
        x, y = deq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and arr[nx][ny]:
                visited[nx][ny] = 1
                deq.append((nx, ny))
    return

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

T = int(input())
for _ in range(T):
    N, M, K = map(int, input().split())
    arr = [[0]*M for _ in range(N)]
    visited = [[0]*M for _ in range(N)]

    for _ in range(K):
        x, y = map(int, input().split())
        arr[x][y] = 1

    cnt = 0
    for i in range(N):
        for j in range(M):
            if not visited[i][j] and arr[i][j]:
                bfs(i, j)
                cnt += 1
    print(cnt)