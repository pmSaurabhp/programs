import threading
import time
class Custom(threading.Thread):
    def run(self):
        for i in range(1,11):
            print("i: "+str(i))
            time.sleep(1)
        print("Custom ends")
        return
class Default:
    def main():
        obj=Custom()
        obj.start()

        for j in range(1,11):
            print("j :"+str(j))
            time.sleep(0.5)
        print("Default ends")
        return
Default.main()
