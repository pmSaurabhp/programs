# my code
# 1 to 3 4-11 12-21 22 23-32 33 34-43 44 45-54 55 56-65 66  67-76 100
#         8    33   44  55   66  77   88  99   99  121  121  121   121
# 121 + 121 = 242
innum =int(input())
if(innum < 4):
    print(innum-1+innum+1)
if(innum>=4 and innum<=11):
    print("8")
else:
    sum = 22
    while(1):
        
        if(innum < sum):
            print(sum*2-11)
            break
        elif(innum == sum):
            print(sum*2)
            break
        else:
            if(sum >=99 )
            sum += 11
        
