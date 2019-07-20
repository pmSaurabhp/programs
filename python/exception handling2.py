class Account:
    def __init__(self,bal):
        self.b=bal
        return
    def put(self,a):
        self.b=self.b+a
        return
    def get(self):
        print("Current Balance :",self.b)
        return
    def withdraw(self,d):
        if self.b>=d:
            self.b=self.b-d
        else:
            error=CustomError("Insufficient Balance")
            raise error
        return
class CustomError(Exception):
    def __init__(self,msg):
        self.e=msg
        return

class bank:
    def main():
        obj=Account(10)
        obj.get()
        try:
            obj.withdraw(20)
            obj.get()
        except Exception as msg:
            print("Exception :",msg)
        obj.put(2000)
        obj.get()
        return
bank.main()    
