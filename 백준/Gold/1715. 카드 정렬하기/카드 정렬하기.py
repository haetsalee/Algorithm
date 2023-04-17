import heapq

N = int(input())
heap = []
for _ in range(N):
    heapq.heappush(heap, int(input()))

temp = 0
result = 0

if N == 1:
    print(result)
else:
    while True:
        if len(heap) == 1:
            temp += heapq.heappop(heap)
            result += temp
            print(result)
            break

        if temp:
            temp += heapq.heappop(heap)
            result += temp
            heapq.heappush(heap, temp)
            temp = 0
        else:
            temp = heapq.heappop(heap)
