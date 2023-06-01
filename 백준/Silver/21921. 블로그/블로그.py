import sys
input = sys.stdin.readline

N, X = map(int, input().split())
visitor = list(map(int, input().split()))

if max(visitor) == 0:
    print('SAD')
else:
    max_visitor = sum(visitor[:X])
    total = max_visitor
    cnt = 1

    for i in range(X, N):
        total -= visitor[i-X]
        total += visitor[i]

        if total > max_visitor:
            max_visitor = total
            cnt = 1
        elif total == max_visitor:
            cnt += 1

    print(max_visitor)
    print(cnt)