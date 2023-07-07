def dfs(x):
    if len(result) == M:
        print(*result)
        return

    for i in range(x, N + 1):
        if i not in result:
            result.append(i)
            dfs(i)
            result.pop()

N, M = map(int,input().split())
result = []
dfs(1)