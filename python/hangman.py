print("***********************            HANGMAN           ***************************")                     
import random
from os import system
global ar
ar=['0']

def main():
    global z
    
    z=random.randint(1,5)
    f=1
    while(f!=0):
        f=0
        for k in range(1,len(ar)):
            if ar[k]==z:
                f=f+1
        if(f==0):
            ar.append(z)
        else:
            z=random.randint(1,5)
            
    n=select(z)            
    
    exit=1
    c=['O']
    for j in range(n-1):
        c.append('O')
    print(c)
    while(exit):
        a=input("Enter a alphabet : ")
        
        for i in range(n):
            if movie[i]==a:
                c.pop(i)
                c.insert(i,a)
                print(c)
        x=0        
        for y in range(n):
            if movie[y]==c[y]:
                x=x+1

        if x==n:
            exit=0
    return
def select(choice):
    print()
    global movie
    if choice==1:
        print("A Marvel Film ???")
        movie="avengers"
        n=len(movie)
        
    elif choice==2:
        print("A Amir Khan Film which earned more in China than India ???")
        movie="dangal"
        n=len(movie)
        
    elif choice==3:
        print("A Horror + Comedy Film ???")
        movie="stree"
        n=len(movie)
    elif choice==4:
        print("A Classic all time best bollywood Film released in 1975 ???")
        movie="sholay"
        n=len(movie)
    else :
        print("A movie about bikes and theft ???")
        movie="dhoom"
        n=len(movie)
        
    return n 
q=0
exit2=1
while(exit2):
    main()
    q=q+1
    if q==5:
        
        exit2=0
        
            
    
