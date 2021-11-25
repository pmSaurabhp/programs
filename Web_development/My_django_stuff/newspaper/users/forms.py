from django import forms
from django.contrib.auth.forms import UserCreationForm,UserChangeForm
from users.models import CustomUser

class CustomUserCreationForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model=CustomUser
        fields=UserCreationForm.Meta.fields+('email','age',)       # password 1 and 2 are by default added

class CustomUserChangeForm(UserChangeForm):
    class Meta():
        model=CustomUser
        fields={'username','email','age'}
