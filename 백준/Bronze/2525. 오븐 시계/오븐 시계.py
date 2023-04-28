H, M = map(int, input().split())
add = int(input())

temp_M = M + add
temp_H = H + temp_M // 60

if temp_M < 60:
    print(H, temp_M)
else:
    if temp_H < 24:
        print(temp_H, temp_M % 60)
    else:
        print(temp_H % 24, temp_M % 60)