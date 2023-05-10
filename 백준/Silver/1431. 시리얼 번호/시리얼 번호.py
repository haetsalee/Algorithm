N = int(input())
arr = []

for _ in range(N):
    temp = input()

    total = 0
    for i in temp:
        if i.isdigit():
            total += int(i)

    arr.append([temp, total])

arr.sort(key=lambda x : (len(x[0]), x[1], x[0]))

for a in arr:
    print(a[0])
