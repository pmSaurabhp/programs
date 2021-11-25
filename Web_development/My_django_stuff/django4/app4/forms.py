from django import forms
from django.core import validators

class form_name(forms.Form):
        Name=forms.CharField()       # input field is created with label Name
        Email=forms.EmailField()
        verify_email=forms.EmailField()
        Text=forms.CharField(required=True,widget=forms.Textarea)

        botcacher=forms.CharField(required=False,widget=forms.HiddenInput,validators=[validators.MaxLengthValidator(0)])

# the bot will fill all the fields Including the hidden field botcacher
# this will increase the length from 0 to some 'n'
        def clean(self):
            all_clean_data=super().clean()       # all_clean_data now holds data of all fields of form
            email=all_clean_data['Email']        #  all_clean_data dictionary[Email] value is assigned to email
            vmail=all_clean_data['verify_email']

            if email != vmail:
                raise forms.ValidationError("Both emails donot match")
