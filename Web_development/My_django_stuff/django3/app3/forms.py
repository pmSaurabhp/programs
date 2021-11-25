from django import forms
from app3.models import User

class New_user_form(forms.ModelForm):
    class Meta():
        model=User         # model attribute links the form to User model
        fields='__all__'   # field attribute as all fields are to be linked
        # these 2 lines make all the input fields
        # and link it to models i.e. database
