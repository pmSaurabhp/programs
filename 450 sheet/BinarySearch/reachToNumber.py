// from number a reach to number b 
// by following operations
// if n is odd decrease by 1, 
// if n is even increse it by 1,
// increase by a factor of 2 ,
// if even increase by factor of 2
def getAns(a,b):
    count=0
    while a!=b:
        if(a>b):
            if(a&1)!=0:
                a-=1
            else:
                a>>=1
        else:
            if(b&1)!=0:
                b-=1
            else:
                b>>=1
        
        count+=1
    
    return count

currentFire, neededFire = [int(i) for i in input().split()]

ans=getAns(currentFire,neededFire)

print(ans)