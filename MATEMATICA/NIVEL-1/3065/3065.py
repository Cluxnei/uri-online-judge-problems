i = 1
while True:
    try:
        n = int(input())
        if n == 0:
            break
        print('Teste ' + str(i))
        print(str(int(eval(input(), {}, {}))))
        print('')
        i += 1
    except:
        break
