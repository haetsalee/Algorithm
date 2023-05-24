from collections import deque

def bfs(x, y):
    deq = deque()
    deq.append((x, y))
    visited[x][y] = 1
    union = [(x, y)]
    total = arr[x][y]

    while deq:
        x, y = deq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                if L <= abs(arr[nx][ny] - arr[x][y]) <= R:
                    visited[nx][ny] = 1
                    deq.append((nx, ny))
                    union.append((nx, ny))
                    total += arr[nx][ny]

    for x, y in union:
        arr[x][y] = total // len(union)

    return len(union)

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

N, L, R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
result = 0

while True:
    visited = [[0]*N for _ in range(N)]
    flag = 0
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                if bfs(i, j) > 1:
                    flag = 1

    if not flag:
        break
    else:
        result += 1

print(result)