from itertools import combinations

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
result = 987654321

for comb in [combinations(arr, i) for i in range(1, N+1)]:
    for c in comb:
        s_total = 1
        b_total = 0
        for s, b in c:
            s_total *= s
            b_total += b
        result = min(result, abs(s_total - b_total))

print(result)