import math

while True:
    try:
        firstChars = []
        uniqueChars = []
        words = input().split(' ')
        for c in words:
            if len(c) > 1:
                firstChars.append(c[0])
            else:
                firstChars.append(c)
        for c in firstChars:
            if c not in uniqueChars:
                uniqueChars.append(c)
        aliterations = 0
        for c in uniqueChars:
            aliterations += firstChars.count(c)
        aliterations = aliterations - len(uniqueChars)
        print(aliterations)
    except EOFError:
        break