line = input().split(' ')
p = int(line[0])
j1 = int(line[1])
j2 = int(line[2])
r = int(line[3])
a = int(line[4])
winner = 1
if r == 0 and a == 0:
    if p == 0 and (j1 + j2) % 2 == 0:
        winner = 2
    if p == 1 and (j1 + j2) % 2 == 0:
        winner = 1
    if p == 0 and (j1 + j2) % 2 != 0:
        winner = 1
    if p == 1 and (j1 + j2) % 2 != 0:
        winner = 2
if r == 1 and a == 1:
    winner = 2
if r == 0 and a == 1:
    winner = 1
if r == 1 and a == 0:
    winner = 1

print('Jogador {} ganha!'.format(winner))
