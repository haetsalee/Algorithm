def dfs(N, M, cnt):
    if cnt == M:
        print(*result)
        return

    for i in range(1, N+1):
        result.append(i)
        dfs(N, M, cnt+1)
        result.pop()

N, M = map(int,input().split())

result = []
dfs(N, M, 0)