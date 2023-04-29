N, K = map(int, input().split())
arr = list(input())
cnt = 0

for i in range(N):
    if arr[i] == "P":
        for j in range(i-K, i+K+1):
            if 0 <= j < N and arr[j] == "H":
                cnt += 1
                arr[j] = 0
                break
print(cnt)