def bubbleSort(alist):
    t = 0
    for passnum in range(len(alist)-1,0,-1):
        for i in range(passnum):
            if alist[i] < alist[i+1]:
                temp = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = temp
            elif alist[i] == alist[i+1]: 
                t += 1
    return t

n = int(input())
for i in range(0, n):
    j = int(input())
    notas = []
    nums = input().split(' ')
    for k in range(0, j):
        notas.append(int(nums[k]))
    print(bubbleSort(notas))