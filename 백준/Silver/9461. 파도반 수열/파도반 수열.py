dp = [1, 1, 1, 2, 2]
for i in range(5, 101):
    dp.append(dp[i-1]+dp[i-5])

T = int(input())
for _ in range(T):
    num = int(input())
    print(dp[num-1])