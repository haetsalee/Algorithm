from itertools import combinations

N = int(input())
L = list(map(int, input().split()))
J = list(map(int, input().split()))

result = 0

for k in range(1, N+1):
    for comb in combinations(range(N), k):
        hp = 0
        for i in comb:
            hp += L[i]
        if hp < 100:
            joy = 0
            for i in comb:
                joy += J[i]
            if joy > result:
                result = joy

print(result)