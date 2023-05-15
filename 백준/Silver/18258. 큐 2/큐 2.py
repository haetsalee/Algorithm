from collections import deque
import sys
input = sys.stdin.readline

T = int(input())
deq = deque()

for _ in range(T):
    temp = list(input().split())
    if temp[0] == 'push':
        deq.append(temp[1])
    elif temp[0] == 'pop':
        if deq:
            print(deq.popleft())
        else:
            print(-1)
    elif temp[0] == 'size':
        print(len(deq))
    elif temp[0] == 'empty':
        if deq:
            print(0)
        else:
            print(1)
    elif temp[0] == 'front':
        if deq:
            print(deq[0])
        else:
            print(-1)
    elif temp[0] == 'back':
        if deq:
            print(deq[-1])
        else:
            print(-1)