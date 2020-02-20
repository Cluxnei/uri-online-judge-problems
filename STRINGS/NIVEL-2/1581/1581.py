n = int(input())
for i in range(0, n):
    k = int(input())
    languages = []
    for j in range(0, k):
        languages.append(input())
    uniqueLanguages = []
    for j in languages:
        if j not in uniqueLanguages:
            uniqueLanguages.append(j)
    print(uniqueLanguages[0] if len(uniqueLanguages) == 1 else 'ingles')