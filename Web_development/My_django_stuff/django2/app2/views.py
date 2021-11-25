from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.

#def index(request):
#    return HttpResponse("<em>Using HTML tags</em>")

def index(request):
    my_dict={'insert_me':"I am coming from app2/views.py"}
    return render(request,'app2/index.html',context=my_dict)
