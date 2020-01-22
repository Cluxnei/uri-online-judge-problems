line = input().split(' ') 
n = int(line[0])
k = int(line[1])

names = list()

for i in range(n):
    names.append(input())

names.sort()

print(names[k - 1])