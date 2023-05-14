N, K = map(int, input().split())
arr = [i for i in range(1, N+1)]
result = []
cnt = 0

for i in range(N):
    cnt += K - 1
    if len(arr) > cnt:
        result.append(arr.pop(cnt))

    elif len(arr) <= cnt:
        cnt = cnt % len(arr)
        result.append(arr.pop(cnt))

print(str(result).replace('[', '<').replace(']', '>'))