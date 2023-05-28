import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(input() for _ in range(N))
arr_set = set(arr)

cnt = 0
for _ in range(M):
    temp = input()
    if temp in arr_set:
        cnt += 1
        
print(cnt)