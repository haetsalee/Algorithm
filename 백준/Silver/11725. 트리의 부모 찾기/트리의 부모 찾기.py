from collections import deque
import sys
input = sys.stdin.readline

def bfs(start):
    deq = deque()
    deq.append(start)

    while deq:
        v = deq.popleft()
        for i in tree[v]:
            if parent[i] == 0:
                parent[i] = v
                deq.append(i)


N = int(input())

tree = [[] for _ in range(N + 1)]
parent = [0 for _ in range(N + 1)]

for i in range(N - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

bfs(1)

for i in parent[2:]:
    print(i)