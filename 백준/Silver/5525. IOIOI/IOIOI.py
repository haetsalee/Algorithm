import sys
input = sys.stdin.readline

def pattern_cnt(p, s):
    cnt = 0
    for i in range(M - len(p) + 1):
        flag = 1
        for j in range(len(p)):
            if p[j] != s[i+j]:
                flag = 0
        if flag:
            cnt += 1
    return cnt

N = int(input())
M = int(input())
s = input()

p = 'I' + 'OI' * N
result = pattern_cnt(p, s)

print(result)