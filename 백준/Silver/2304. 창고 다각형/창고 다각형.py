N = int(input())
arr = [0] * 1001

max_height = max_idx = 0
for _ in range(N):
    idx, height = map(int, input().split())
    arr[idx] = height

    if height > max_height:
        max_height = height
        max_idx = idx

result = max_height

front = back = 0

for i in range(max_idx):
    if arr[i] <= max_height and arr[i] > front:
        front = arr[i]
    result += front

for i in range(1000, max_idx, -1):
    if arr[i] <= max_height and arr[i] > back:
        back = arr[i]
    result += back

print(result)