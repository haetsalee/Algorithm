N = int(input())
card = list(range(1, N+1))

stack = []
while len(card) != 1:
    stack.append(card.pop(0))
    card.append(card.pop(0))

stack.append(card[0])
print(*stack)