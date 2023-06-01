def solution(babbling):
    words = ['aya', 'ye', 'woo', 'ma']
    ans = 0
    
    for babble in babbling:
        for word in words:
            if word in babble:
                babble = babble.replace(word, '1')
        
        if babble.isdigit():
            ans += 1
    
    return ans