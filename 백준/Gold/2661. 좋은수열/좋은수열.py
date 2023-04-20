def check(num):
    for i in range(0, len(num) // 2 + 1):
        if num[-i:] == num[-(i*2):-i]:
            return 0
    return 1

def dfs(num, cnt):
    if cnt == N:
        print(num)
        exit()

    for i in range(1, 4):
        if check(num + str(i)):
            dfs(num + str(i), cnt + 1)

N = int(input())
dfs('1', 1)