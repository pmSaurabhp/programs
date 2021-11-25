from django.shortcuts import render
from app6.forms import UserForm,UserProfileForm

# imports for login and logout
from django.contrib.auth import authenticate,login,logout
from django.http import HttpResponse,HttpResponseRedirect
from django.urls import reverse
from django.contrib.auth.decorators import login_required

# Create your views here.
def index(request):
    return render(request,'app6/index.html')

def register(request):
    registered=False

    if request.method =='POST':
        user_form=UserForm(data=request.POST)         # get the data from form fields
        profile_form=UserProfileForm(request.POST)

        if user_form.is_valid and profile_form.is_valid:

            user=user_form.save()
            user.set_password(user.password) # set_password converts password into hash string and hash is saved as password in database
            user.save()

            profile=profile_form.save(commit=False)
            profile.user=user                    # profile.user has empty username,email,password
                                                # which are given value of user
            if 'profile_pic' in request.FILES:
                profile.profile_pic=request.FILES['profile_pic']  # request.FILES is a dictionary that stores keys
                                                                  # of upladed images and files
            profile.save()

            registered=True
        else:
            print(user_form.error,profile_form.error)
    else:
        user_form=UserForm()
        profile_form=UserProfileForm()

    return render(request,'app6/registration.html',{'user_form':user_form,
                                                    'profile_form':profile_form,
                                                    'registered':registered})
@login_required             # decorators i.e. if user is login then he can logout
def user_logout(request):
    logout(request)
    return HttpResponseRedirect(reverse('index'))    # reverse searches for given url in urls.py
  # render(request,'app6/index.html')  can also be used

def user_login(request):
    if request.method == 'POST':
        user_name=request.POST.get('user_name')  #  < input type='text' name='user_name'>
        password=request.POST.get('password')

        user=authenticate(username=user_name,password=password)  # checks from database if username and password are correct

        if user:
            login(request,user)                  # attach a flag that user has logged in
            return HttpResponseRedirect(reverse('index')) # and redirect him to his account but we dont have profile page
        else:
            print("someone tried to login and failed")
            print("Username: {} password: {}".format(user_name,password))
            return HttpResponse("invalid Username or password")
    else:
        return render(request,'app6/login.html')
