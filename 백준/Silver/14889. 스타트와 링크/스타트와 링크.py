def dfs(cnt, idx):
    global result

    if cnt == N // 2:
        total1, total2 = 0, 0
        for i in range(N):
            for j in range(N):
                if visited[i] and visited[j]:
                    total1 += arr[i][j]
                elif not visited[i] and not visited[j]:
                    total2 += arr[i][j]
        result = min(result, abs(total1-total2))
        return

    for i in range(idx, N):
        if not visited[i]:
            visited[i] = 1
            dfs(cnt+1, i+1)
            visited[i] = 0


N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

visited = [0] * N
result = 987654321

dfs(0, 0)
print(result)