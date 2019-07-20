class custom:
    def fun(self):
        for i in range(1,51):
            print("i: ",i)
        return
class Default:
    def main():
        obj=custom()
        obj.fun()

        for j in range(1,51):
            print("j :",j)
        return
Default.main()
