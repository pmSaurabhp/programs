class Account:
    def __init__(self,b):
        self.x=b               # x is object level variable
        print("self",id(self)) # argument b stores value passed when calling constructor
        return
              
    def main():
        a1=Account(5000)
        a2=Account(8000)
        print("a1 = ",id(a1),id(a1.x),type(a1))
        print("a2 = ",id(a2),type(a2))
        return
Account.main()
