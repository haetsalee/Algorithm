N = int(input())
arr = [int(input()) for _ in range(N)]
arr.sort(reverse=True)

result = 0
for i in range(N):
    if arr[i] * (i+1) > result:
        result = arr[i] * (i+1)

print(result)