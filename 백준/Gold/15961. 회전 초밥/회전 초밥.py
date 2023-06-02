import sys
input = sys.stdin.readline
from collections import defaultdict

N, M, K, coupon = map(int, input().split())
sushi = list(int(input()) for _ in range(N))
sushi += sushi[:K-1]

max_cnt = 0
cnt_sushi = defaultdict(int)
cnt_sushi[coupon] += 1

for i in range(K):
    cnt_sushi[sushi[i]] += 1

for i in range(K, len(sushi)):
    max_cnt = max(max_cnt, len(cnt_sushi))

    cnt_sushi[sushi[i-K]] -= 1
    if cnt_sushi[sushi[i-K]] == 0:
        del cnt_sushi[sushi[i-K]]

    cnt_sushi[sushi[i]] += 1

print(max_cnt)