import sys

def checked(n, r, c):
    global result

    if r == R and c == C:
        print(int(result))
        exit(0)

    if not (r <= R < r + n and c <= C < c + n):
        result += n * n
        return

    checked(n/2, r, c) 
    checked(n/2, r, c + n/2)
    checked(n/2, r + n/2, c)
    checked(n/2, r + n/2, c + n/2) 

N, R, C = map(int, sys.stdin.readline().split())
result = 0

checked(2 ** N, 0, 0)