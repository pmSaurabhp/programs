from django.shortcuts import render

# Create your views here.
from django.urls import reverse_lazy
from django.views.generic import CreateView
from django.contrib.auth.forms import UserCreationForm

class SignUpView(CreateView):
    form_class=UserCreationForm
    success_url=reverse_lazy('login')                # reverse_lazy is used as when CreateView  is imported
    template_name='registration\signup.html'           #  the urls take time to load
