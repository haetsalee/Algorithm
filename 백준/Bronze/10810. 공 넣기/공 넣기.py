N, M = map(int, input().split())
arr = [0] * (N+1)

for _ in range(M):
    x, y, z = map(int, input().split())
    for i in range(x, y+1):
        arr[i] = z

for i in range(1, N+1):
    print(arr[i], end=' ')
