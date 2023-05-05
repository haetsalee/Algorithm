from collections import deque

def bfs(x):
    deq = deque()
    deq.append(x)
    visited[x] = 0

    while deq:
        x = deq.popleft()

        if x == 100:
            return

        for i in range(1, 7):
            nx = x + i
            if nx > 100:
                break
            nx = arr[nx]
            if visited[nx] == -1:
                deq.append(nx)
                visited[nx] = visited[x] + 1

N, M = map(int, input().split())
arr = list(range(101))
visited = [-1] * 101

for i in range(N):
    s, e = map(int, input().split())
    arr[s] = e
for j in range(M):
    s, e = map(int, input().split())
    arr[s] = e

bfs(1)
print(visited[100])
