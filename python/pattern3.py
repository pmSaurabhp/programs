def pattern():
    for i in range(1,7):
        for j in range(7,i,-1):
            print(" ",end='')
        for k in range(1,i):
            print("*",end='')

        print()
    return
pattern()