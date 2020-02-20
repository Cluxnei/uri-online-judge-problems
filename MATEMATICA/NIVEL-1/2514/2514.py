def mdc(a, b):
    return a if b == 0 else mdc(b, a % b)


def mmc(a, b):
    return abs(a * b) / mdc(a, b)


while True:
    try:
        lastAlign = int(input())
        line = input().split(' ')
        l1 = int(line[0])
        l2 = int(line[1])
        l3 = int(line[2])
        days = int(mmc(mmc(l1, l2), l3) - lastAlign)
        print(days)
    except EOFError:
        break

