n = int(input())
for i in range(0, n):
    nums = input().split(' ')
    if nums[0] == nums[1]:
        print('encaixa')
        continue
    l = len(nums[1])
    print('encaixa' if  nums[1] == nums[0][len(nums[0]) - l:] else 'nao encaixa')