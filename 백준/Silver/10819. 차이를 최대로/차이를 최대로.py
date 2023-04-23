import itertools

N = int(input())
arr = list(map(int, input().split()))

result = 0
permu = itertools.permutations(arr, N)

for p in permu:
    temp = 0
    for i in range(N - 1):
        temp += abs(p[i] - p[i+1])

    if temp > result:
        result = temp

print(result)