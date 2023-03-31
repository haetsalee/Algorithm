num = int(input())
result = 0

for i in range(1, num+1):
    if i < 100:
        result += 1
    elif i < 1000:
        if (i % 10 -i // 10% 10 == i // 10%10-i//100):
            result += 1
print(result)