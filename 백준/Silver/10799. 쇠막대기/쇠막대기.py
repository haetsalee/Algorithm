arr = list(input())
cnt = 0
stack = []

for i in range(len(arr)):
    if arr[i] == '(':
        stack.append('(')

    else:
        if arr[i - 1] == '(':
            stack.pop()
            cnt += len(stack)

        else:
            stack.pop()
            cnt += 1 

print(cnt)