n=int(input("Enter n = "))

def pattern(n):
    for i in range(1,n):
        for a in range(1,n):
            for j in range(n,i+1,-1):
                print(" ",end='')
            for k in range(1,2*i-2):
                print("*",end='')
            for s in range(n,i,-1):
                print(" ",end='')
        print()

    return
pattern(n)