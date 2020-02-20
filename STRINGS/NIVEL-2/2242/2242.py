def isConsonant(c):
    return c not in ['a', 'e', 'i', 'o', 'u']

sequence = ''
for c in input():
    if not isConsonant(c):
        sequence += c
print('S' if sequence == sequence[::-1] else 'N')

