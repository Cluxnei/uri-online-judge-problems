while True:
    try:
        codes = []
        n = int(input())
        for i in range(0, n):
            codes.append(input())
        codes.sort()
        for i in codes:
            print(i)
    except EOFError:
        break