total = int(input())
N = int(input())
result = 0
for _ in range(N):
    price, cnt = map(int, input().split())
    result += price * cnt

if total == result:
    print('Yes')
else:
    print('No')