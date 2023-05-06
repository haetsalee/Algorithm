import sys, heapq
input = sys.stdin.readline

INF = 987654321
N = int(input())
M = int(input())
arr = [[] for _ in range(N+1)]
distance = [INF] * (N+1)
for _ in range(M):
    A, B, C = map(int,input().split())
    arr[A].append((B, C))
start, end = map(int, input().split())

def dijkstra(start):
    q = []
    heapq.heappush(q, (start, 0))
    distance[start] = 0
    while q:
        now_node, dist = heapq.heappop(q)
        if distance[now_node] < dist:
            continue
        for n_n, weight in arr[now_node]:
            cost = dist + weight
            if cost < distance[n_n]:
                distance[n_n] = cost
                heapq.heappush(q,(n_n, cost))

dijkstra(start)
print(distance[end])