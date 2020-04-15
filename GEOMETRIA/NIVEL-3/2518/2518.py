import math
while True:
    try:
        steps = int(input())
        line = input().split(' ')
        h, c, li = int(line[0]), int(line[1]), int(line[2])
        hypot = math.sqrt(h ** 2 + c ** 2)
        print('{:.4f}'.format(li * steps * hypot / 10000))
    except EOFError:
        break
