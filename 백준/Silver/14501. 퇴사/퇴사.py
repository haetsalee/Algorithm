N = int(input())

temp = [list(map(int, input().split())) for _ in range(N)]
dp = [0 for _ in range(N + 1)]

for i in range(N-1, -1, -1):
    if temp[i][0] + i > N:
        dp[i] = dp[i + 1]

    else:
        dp[i] = max(dp[i + 1], dp[temp[i][0] + i] + temp[i][1])  # 오늘 상담을 안 할 경우와 상담을 할 경우 중 max 값

print(dp[0])