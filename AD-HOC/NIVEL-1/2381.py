line = input().split(' ') 
n = int(line[0])
x = int(line[1])

nomes = list()

for i in range(n):
    nomes.append(input())

nomes.sort()

print(nomes[x - 1])