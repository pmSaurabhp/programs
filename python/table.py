l=int(input("Enter lower limit = "))
u=int(input("Enter upper limit = "))
def table(l,u):
    for j in range(l,u+1):
        for i in range(1,11):
            print(j,"X",i,"=",j*i)
        print()
    return
table(l,u)