import math

while True:
    try:
        line = input().split(' ')
        m1, m2, m3 = float(line[0]), float(line[1]), float(line[2])
        x = float((m1 + m2 + m3) / 2)
        s = x * (x - m1) * (x - m2) * (x - m3)
        try:
            area = 4 / 3 * math.sqrt(s)
            print('{:.3f}'.format(area))
        except Exception:
            print('-1.000')
    except EOFError:
        break
