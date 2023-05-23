N = int(input())
str = list(input())

for i in range(N-1):
    temp = list(input())
    for j in range(len(str)):
        if (str[j] != temp[j]):
            str[j] = "?"
            
print(''.join(str))