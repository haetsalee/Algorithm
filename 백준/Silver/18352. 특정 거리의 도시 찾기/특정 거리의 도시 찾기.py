from collections import deque
import sys
input = sys.stdin.readline


def bfs(x):
    deq = deque([x])
    visited[x] = 1

    while deq:
        x = deq.popleft()

        if visited[x] == k + 1:
            result.append(x)
            continue

        for i in arr[x]:
            if visited[i] == 0:
                deq.append(i)
                visited[i] = visited[x] + 1

N, M, k, x = map(int, input().split())
arr = [[] for _ in range(N + 1)]
visited = [0 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    arr[a].append(b)

result = []

bfs(x)

if result:
    result.sort()
    for i in result:
        print(i)
else:
    print(-1)
