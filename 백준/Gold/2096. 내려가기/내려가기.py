import sys
read = sys.stdin.readline

N = int(read())
arr = []

max_dp = [[0 for _ in range(3)] for _ in range(2)]
min_dp = [[0 for _ in range(3)] for _ in range(2)]
for i in range(N):
    temp = list(map(int, read().split()))

    max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + temp[0]
    min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + temp[0]

    max_dp[1][1] = max(max_dp[0][0], max_dp[0][1], max_dp[0][2]) + temp[1]
    min_dp[1][1] = min(min_dp[0][0], min_dp[0][1], min_dp[0][2]) + temp[1]

    max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + temp[2]
    min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + temp[2]

    max_dp[0][0], max_dp[0][1], max_dp[0][2] = max_dp[1][0], max_dp[1][1], max_dp[1][2]
    min_dp[0][0], min_dp[0][1], min_dp[0][2] = min_dp[1][0], min_dp[1][1], min_dp[1][2]

print(max(max_dp[1]), min(min_dp[1]))