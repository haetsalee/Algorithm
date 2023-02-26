from collections import deque

def bfs(x, y):
    global cnt
    deq = deque()
    deq.append((x, y))
    visited[x][y] = 1

    while deq:
        x, y = deq.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < M and 0 <= ny < N and arr[nx][ny] == arr[x][y] and not visited[nx][ny]:
                cnt += 1
                deq.append((nx, ny))
                visited[nx][ny] = 1

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

N, M = map(int, input().split())
arr = [list(input()) for _ in range(M)]
visited = [[0]*N for _ in range(M)]

whiteScore = blueScore = 0

for i in range(M):
    for j in range(N):
      cnt = 1
      if not visited[i][j]:
          if arr[i][j] == 'W':
              bfs(i, j)
              whiteScore += cnt ** 2
          else:
              bfs(i, j)
              blueScore += cnt ** 2

print(whiteScore, blueScore)