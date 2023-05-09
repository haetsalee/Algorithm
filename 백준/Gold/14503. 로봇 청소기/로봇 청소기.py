def dfs(x, y, d):
    global cnt

    if arr[x][y] == 0:
        arr[x][y] = 9
        cnt += 1

    for k in range(4):
        d = (d + 3) % 4
        nx = x + dx[d]
        ny = y + dy[d]
        if 0 <= nx < N and 0 <= ny < M and arr[nx][ny] == 0:
            dfs(nx, ny, d)
            return

    nx = x - dx[d]
    ny = y - dy[d]
    if arr[nx][ny] == 1:
        print(cnt)
        return

    dfs(nx, ny, d)

    
N, M = map(int, input().split())
x, y, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

arr[x][y] = 9
cnt = 1

dfs(x, y, d)