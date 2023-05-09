import sys
from collections import deque
input = sys.stdin.readline

def bfs(x, y):
    deq = deque()
    deq.append((x, y))

    while deq:
        x, y = deq.popleft()
        if abs(x - goal[0]) + abs(y - goal[1]) <= 1000:
            return 1

        for k in range(N):
            if not visited[k]:
                nx, ny = mid[k]
                if abs(x-nx) + abs(y-ny) <= 1000:
                    deq.append((nx, ny))
                    visited[k] = 1
    return 0

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    home = list(map(int, input().split()))
    mid = [list(map(int, input().split())) for _ in range(N)]
    goal = list(map(int, input().split()))
    visited = [0] * (N+1)

    if bfs(home[0], home[1]):
        print('happy')
    else:
        print('sad')