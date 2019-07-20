n=int(input("Enter n ="))

def perfect(n):

    for j in range(1,n):
        sum=0
        for i in range(1,j):
            if j%i==0:
                sum=sum+i
        if j==sum:
            print(j,end=' ')
    print(" are  perfect no. between 1 to ",n)
    return

perfect(n)