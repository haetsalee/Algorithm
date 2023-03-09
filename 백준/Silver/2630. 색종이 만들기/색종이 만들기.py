import sys
input = sys.stdin.readline
def paper(x, y, N):
    global white, blue
    check = arr[x][y]

    for i in range(x, x + N):
        for j in range(y, y + N):
            if check != arr[i][j]:
                for k in range(2):
                    for l in range(2):
                        paper(x + k * N//2, y + l * N//2, N//2)
                return

    if check == 0:
        white += 1
    else:
        blue += 1

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
blue = white = 0

paper(0, 0, N)
print(white)
print(blue)