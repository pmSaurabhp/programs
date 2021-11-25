from django.shortcuts import render

# Create your views here.
def index(request):
    dict={'text':'hello world','number':100}
    return render(request,'basic_app/index.html',context=dict)

def relative(request):
    return render(request,'basic_app/relativ_url_template.html')

def other(request):
    return render(request,'basic_app/other.html')
