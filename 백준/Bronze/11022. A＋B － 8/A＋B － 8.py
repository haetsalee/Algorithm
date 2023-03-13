N = int(input())
for tc in range(1, N+1):
    a, b = map(int, input().split())
    print(f'Case #{tc}: {a} + {b} =', a+b)