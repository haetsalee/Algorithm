from heapq import heappush, heappop

N, M = map(int, input().split())
gifts = list(map(int, input().split()))
kids = list(map(int, input().split()))

box = []
for gift in gifts:
    heappush(box, -gift)

result = 1
for kid in kids:
    gift = -heappop(box)

    if kid < gift:
        heappush(box, (kid - gift))

    elif kid == gift:
        continue

    else:
        result = 0
        break

print(result)

