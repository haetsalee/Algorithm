def dfs(x, y, temp, cnt):
    global num
    if cnt == 6:
        num.add(temp)
        return

    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if 0 <= nx < 5 and 0 <= ny < 5:
            dfs(nx, ny, temp + arr[nx][ny], cnt + 1)

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

arr = [list(map(str, input().split())) for _ in range(5)]
num = set()

for i in range(5):
    for j in range(5):
        dfs(i, j, arr[i][j], 1)
print(len(num))