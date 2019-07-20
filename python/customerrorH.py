class CustomError(Exception):
    def _init_(self,name):
        self.name=name
        return
class RaiseException:
    def main():
        obj=CustomError("error message")
        raise obj
RaiseException.main()
