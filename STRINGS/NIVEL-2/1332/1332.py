def toInt(word):
    if 'o' in word and 'e' in word or ('n' in word and 't' not in word):
        return 1
    elif 'thr' not in word and 'o' in word and 't' in word and 'e' not in word or ('t' in word and 'w' in word) or ('w' in word and 'o' in word):
        return 2
    else:
        return 3

n = int(input())
for i in range(0, n):
    print(toInt(input()))