from django.shortcuts import render

# Create your views here.
from app4 import forms

def index(request):
    return render(request,'app4/index.html')

def form_view(request):
    form_obj=forms.form_name()

    if request.method == 'POST':
            form_obj=forms.form_name(request.POST)

            if form_obj.is_valid():
                print("Name : "+form_obj.cleaned_data['Name'])
                print("Email : "+form_obj.cleaned_data['Email'])
                print("Text : "+form_obj.cleaned_data['Text'])
    form_dict={'form_input':form_obj}
    return render(request,'app4/forms.html',context=form_dict)
