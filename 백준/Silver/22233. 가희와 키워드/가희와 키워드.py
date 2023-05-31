import sys
input = sys.stdin.readline

N, M = map(int, input().split())
memos = {}
for _ in range(N):
    memos[input().rstrip()] = False

for _ in range(M):
    keywords = map(str, input().rstrip().split(','))
    for keyword in keywords:
        if keyword in memos.keys():
            if memos[keyword] == False:
                memos[keyword] = True
                N -= 1

    print(N)