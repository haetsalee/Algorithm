from heapq import heappush, heappop
N = int(input())

num = []
for _ in range(N):
    arr = map(int, input().split())
    for i in arr:
        if len(num) < N:
            heappush(num, i)
        else:
            if num[0] < i:
                heappop(num) 
                heappush(num, i)

print(num[0])