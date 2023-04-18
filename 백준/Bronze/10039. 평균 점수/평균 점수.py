total = 0
for _ in range(5):
    temp = int(input())
    if temp >= 40:
        total += temp
    else:
        total += 40

print(total // 5)