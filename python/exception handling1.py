class division:
    def main():
        try:
            print("Enter 2 integers ")
            a=int(input())            # r=10/0           
            b=int(input())            # a=sks
            r=a/b
            print("result = ",r)

        except ValueError:
            print("EXCEPTION :invalid input")
        
        print("end reached")    # if program terminates abnormaly 
        return                  # below instructions do not execute
division.main()
        
