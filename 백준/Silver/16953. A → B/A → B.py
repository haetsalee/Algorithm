A, B = map(int, input().split())
cnt = 1
while (B != A):
    cnt += 1
    num = B
    if B % 10 == 1:
        B //= 10
    elif B % 2 == 0:
        B //= 2

    if num == B:
        print(-1)
        break
else:
    print(cnt)