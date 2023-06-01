def line(dot1, dot2):
    return (dot1[1] - dot2[1]) - (dot1[0]-dot2[0])

def solution(dots):
    answer = 0
    if line(dots[0], dots[1]) == line(dots[2], dots[3]):
        answer = 1
    if line(dots[0], dots[2]) == line(dots[1], dots[3]):
        answer = 1
    if line(dots[0], dots[3]) == line(dots[1], dots[2]):
        answer = 1
    
    return answer
