def dfs(x, cnt):
    if cnt == M:
        print(*result)
        return

    for i in range(x, N):
        if arr[i] not in result:
            result.append(arr[i])
            dfs(i+1, cnt+1)
            result.pop()

N, M = map(int,input().split())
arr = sorted(list(map(int, input().split())))
result = []
dfs(0, 0)