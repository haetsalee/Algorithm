from collections import deque

def bfs():
    deq = deque()
    deq.append(N)

    while deq:
        x = deq.popleft()

        if x == K:
            return arr[K]

        for nx in (x-1, x+1, x*2):
            if 0 <= nx <= 100000 and arr[nx] == 0:
                arr[nx] = arr[x] + 1
                deq.append(nx)

N, K = map(int, input().split())
arr = [0] * 100001
print(bfs())