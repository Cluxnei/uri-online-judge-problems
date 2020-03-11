operation = input()
array = []
s = 0
for i in range(0, 12):
    array.append([])
    for j in range(0, 12):
        array[i].append(int(input()))
k = 0
for i in range(0, 12):
    if i == 0 or i == 11:
        continue
    for j in range(0, 5):
        if i <= 5 and i != 6:
            k += 1
        elif i >= 6:
            k -= 1
        if j < k:
            s += array[i][j]

print(s)
