def dfs():
    if len(result) == M:
        print(*result)
        return

    for i in range(N):
        if num[i] not in result:
            result.append(num[i])
            dfs()
            result.pop()

N, M = map(int,input().split())
num = list(map(int, input().split()))
num.sort()
result = []
dfs()