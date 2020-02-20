def win(rajesh, sheldon):
    return 'rajesh' if rajesh in {
        'papel': ['tesoura', 'lagarto'],
        'tesoura': ['spock', 'pedra'],
        'pedra': ['papel', 'spock'],
        'spock': ['papel', 'lagarto'],
        'lagarto': ['pedra', 'tesoura']
    }.get(sheldon) else 'sheldon'

c = int(input())
for i in range(0, c):
    line = input().split(' ')
    if (line[0] == line[1]):
        print('empate')
    else:
        print(win(line[0], line[1]))