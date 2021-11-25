from django.shortcuts import render
from app3.models import User
# Create your views here.
def index(response):
    return render(response,'app3/index.html')

def users(response):
    user_list=User.objects.order_by('first_name')
    user_dict={'user_database':user_list}
    return render(response,'app3/user.html',context=user_dict)
