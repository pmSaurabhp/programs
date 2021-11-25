from django.contrib import admin

# Register your models here.
from inventory.models import Product,Cart
admin.site.register(Product)
admin.site.register(Transaction)
