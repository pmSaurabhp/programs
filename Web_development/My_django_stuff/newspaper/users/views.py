from django.shortcuts import render

# Create your views here.
from django.urls import reverse_lazy
from django.views.generic import CreateView,TemplateView
from users.forms import CustomUserCreationForm

class HomeView(TemplateView):
    template_name='home.html'
    context_object_name='object'


class SignUpView(CreateView):
    form_class=CustomUserCreationForm
    success_url=reverse_lazy('login')                # reverse_lazy is used as when CreateView  is imported
    template_name='signup.html'           #  the urls take time to load
