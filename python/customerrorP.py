class CustomError(Exception):
    def _init_(self,name):
        self.name=name
        return
class RaiseException:
    def main():
        try:
            obj=CustomError("error message")
            raise obj
        except Exception as msg:
            print("EXCEPTION :",msg)
RaiseException.main()
