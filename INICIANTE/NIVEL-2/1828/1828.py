def win(rajesh, sheldon):
    return 'Bazinga!' if rajesh.lower() in {
        'papel': ['tesoura', 'lagarto'],
        'tesoura': ['spock', 'pedra'],
        'pedra': ['papel', 'spock'],
        'spock': ['papel', 'lagarto'],
        'lagarto': ['pedra', 'tesoura']
    }.get(sheldon.lower()) else 'Raj trapaceou!'


c = int(input())
for i in range(0, c):
    line = input().split(' ')
    if line[0] == line[1]:
        print('Caso #{}: De novo!'.format(i + 1))
    else:
        print('Caso #{}: '.format(i + 1) + win(line[0], line[1]))

