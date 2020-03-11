while True:
    n = int(input())
    if n == 0:
        break
    wave, sequence, pic = [], [0], 0

    for i in input().split(' '):
        wave.append(int(i))

    for i in wave:
        if i > max(sequence) or i < min(sequence):
            pic += 1
        sequence.append(i)

    print(pic)
