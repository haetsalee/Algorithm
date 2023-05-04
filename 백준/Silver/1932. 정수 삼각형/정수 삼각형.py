N = int(input())

num = [list(map(int, input().split())) for _ in range(N)]

for i in range(1, N):
    for j in range(i + 1):
        if j == 0:
            num[i][0] += num[i - 1][0]
        elif j == i:
            num[i][-1] += num[i - 1][-1]
        else:
            num[i][j] += max(num[i - 1][j], num[i - 1][j - 1])

print(max(num[-1]))