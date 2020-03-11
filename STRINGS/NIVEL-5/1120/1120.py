while True:
    line = input().split(' ')
    n = int(line[0])
    n2 = int(line[1])
    if n == n2 and n == 0:
        break
    num = line[1].replace(line[0], '')
    print(int(num) if num != '' else 0)
