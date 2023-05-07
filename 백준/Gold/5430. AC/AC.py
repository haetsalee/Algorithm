import sys
input = sys.stdin.readline
from collections import deque

T = int(input())
for _ in range(T):
    order = input().rstrip()
    N = int(input())
    deq = deque(input().rstrip()[1:-1].split(','))

    if N == 0:
        deq.clear()

    flag = 1
    cnt = 0
    for i in range(len(order)):
        if order[i] == 'R':
            cnt += 1
        else:
            if len(deq) and cnt % 2 == 0:
                deq.popleft()
            elif len(deq) and cnt % 2:
                deq.pop()
            else:
                flag = 0

    if cnt % 2:
        deq.reverse()

    if flag:
        print('['+','.join(deq)+']')
    else:
        print('error')