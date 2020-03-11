line = input().split(' ')
happy, sad = ':)', ':('
a, b, c = int(line[0]), int(line[1]), int(line[2])
if b < a and (b < c or b == c):
    print(happy)
elif b > a and (b == c or c < b):
    print(sad)
elif a < b < c and b - c < b - a:
    print(sad)
elif a < b < c and c - b >= b - a:
    print(happy)
elif a > b > c and b - c < a - b:
    print(happy)
elif a > b > c and b - c >= a - b:
    print(sad)
if a == b:
    print(happy if c > b else sad)



