class division:
    def main():
        try:
            print("Enter 2 integers ")
            a=int(input())            # r=10/0           
            b=int(input())            # a=sks
            r=a/b
            print("result = ",r)

        except Exception as msg:
            print("EXCEPTION ",msg)
        return
division.main()
        
