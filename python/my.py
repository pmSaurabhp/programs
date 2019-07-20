r=int(input("no. of rows"))
i=1
while i<=r:
    j=r
    while j>=i:
        print(" ")
        j=j-1
    k = 1
    while k <= 2*i-1:
        print("*")
        k = k + 1
    i=i+1
    print()
