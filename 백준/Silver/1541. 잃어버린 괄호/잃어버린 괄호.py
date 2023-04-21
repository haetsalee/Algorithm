temp = list(input().split('-'))
result = []

for xx in temp:
    xx = xx.split('+')
    total = 0
    for x in xx:
        total += int(x)
    result.append(total)

ans = result[0]
for i in range(1, len(result)):
    ans -= result[i]

print(ans)