class Account:
    def __init__(self,b):
        self.x=b
        return
    def putBalance(self,c):
        self.x=self.x+c
        return
    def getBalance(self):
        print("Balance",self.x)
        return
    def withdraw(self,d):
        self.x=self.x-d
        return

class Bank:
    def main():    
        obj=Account(10)
        obj.getBalance()
        
        b=int(input("Enter Amount to deposit = "))
        obj.putBalance(b)
        obj.getBalance()
        
        d=int(input("Enter Amount to withdraw = "))
        obj.withdraw(d)
        obj.getBalance()
        return
Bank.main()
    
        
