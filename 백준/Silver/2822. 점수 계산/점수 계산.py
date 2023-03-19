score = []
for i in range(8):
    N = int(input())
    score.append([i+1, N])

score.sort(key=lambda x : x[1])

total = 0
idx = []
for i in range(3, 8):
    total += score[i][1]
    idx.append(score[i][0])
idx.sort()

print(total)
print(*idx)
