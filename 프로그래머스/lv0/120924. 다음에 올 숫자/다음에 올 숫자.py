def solution(common):
    answer = 0
    
    temp = common[1] - common[0]
    if temp == common[2] - common[1]:
        answer = common[-1] + temp
        
    else:
        temp = common[1] / common[0]
        answer = common[-1] * temp
        
    return answer