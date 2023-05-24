while True:
    word = input()
    if word == "*":
        break

    for i in range(1, len(word) - 1):
        pairs = set()
        flag = 0
        for j in range(len(word) - i):
            pair = word[j] + word[i + j]
            if pair in pairs:
                print(word, "is NOT surprising.")
                flag = 1
                break
            else:
                pairs.add(pair)

        if flag:
            break
    else:
        print(word, "is surprising.")