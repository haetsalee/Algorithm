N, M = map(int, input().split())

arr = [0] + [i for i in range(1, N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    arr[a], arr[b] = arr[b], arr[a]

for i in range(1, N + 1):
    print(arr[i], end=' ')