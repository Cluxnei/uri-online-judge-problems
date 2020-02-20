while True:
    line = input().split(' ')
    n1 = int(line[0])
    n2 = int(line[1])
    if (n1 == n2 and n1 == 0):
        break
    print(str(n1 + n2).replace('0', ''))