from django.shortcuts import render
# from app3.models import User
from app3.forms import New_user_form
# Create your views here.

def index(response):
    return render(response,'app3/index.html')


 #  this project shows how form is linked to models i.e. database
def users(request):

    form_obj=New_user_form()
    if request.method=='POST':                # means when submit is pressed
        form_obj=New_user_form(request.POST)
        if form_obj.is_valid():
            form_obj.save(commit=True)        # saves the data back in database
            return index(request)             # back to home page
        else:
            print("form not valid")

    return render(request,'app3/user.html',{'form_insert':form_obj})
