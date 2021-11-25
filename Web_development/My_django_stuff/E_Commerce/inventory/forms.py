from django import forms
from .models import Product, Transaction


class ProductForm(forms.ModelForm):

    class Meta:
        model = Product
        fields = "__all__"


class CartForm(forms.ModelForm):

    class Meta:
        model = Transaction
        fields = ('purchase_date','buyer_name')
