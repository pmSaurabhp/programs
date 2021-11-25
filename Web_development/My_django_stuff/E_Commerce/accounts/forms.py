from django import forms
from django.contrib.auth.forms import UserCreationForm,UserChangeForm
from django.contrib.auth.models import User

class CustomUserCreationForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model=User
        fields=UserCreationForm.Meta.fields+('email',)       # password1 and 2 are by default added

class CustomUserChangeForm(UserChangeForm):
    class Meta():
        model=User
        fields={'username','email'}
