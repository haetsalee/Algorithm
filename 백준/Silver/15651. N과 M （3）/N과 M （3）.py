def dfs(x, cnt):
    if cnt == M:
        print(*result)
        return

    for i in range(1, N+1):
        result.append(i)
        dfs(i+1, cnt+1)
        result.pop()

N, M = map(int,input().split())

result = []
dfs(0, 0)