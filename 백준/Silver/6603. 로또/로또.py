from itertools import combinations

while True:
    num = list(map(int, input().split()))
    if num.pop(0) == 0:
        break

    for lotto in combinations(num, 6):
        print(*lotto)
    print()