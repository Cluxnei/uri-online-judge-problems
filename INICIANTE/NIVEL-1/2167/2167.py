n = int(input())
numbers = input().split(' ')
i = 0
while i < n - 1:
    if int(numbers[i + 1]) < int(numbers[i]):
        print(i + 2)
        exit(0)
    i += 1
print(0)

