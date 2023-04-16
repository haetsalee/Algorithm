N = int(input())
word = list(input())
arr = [list(input()) for _ in range(N-1)]

result = 0

for a in arr:
    cnt = 0
    for w in word:
        if w in a:
            a.remove(w)
        else:
            cnt += 1

    if cnt <= 1 and len(a) <= 1:
        result += 1

print(result)