arr = list(map(int, input().split()))
num = [1, 1, 2, 2, 2, 8]

for i in range(6):
    print(num[i] - arr[i], end=" ")