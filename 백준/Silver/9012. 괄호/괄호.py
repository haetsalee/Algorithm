T = int(input())
for _ in range(T):
    stack = []
    temp = list(input())
    for i in temp:
        if i == '(':
            stack.append('(')
        else:
            if stack:
                stack.pop()
            else:
                print("NO")
                break
    else:
        if stack:
            print("NO")
        else:
            print("YES")
