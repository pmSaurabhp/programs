from django.db import models
from django.utils import timezone
from django.urls import reverse
# Create your models here.
class Product(models.Model):
    product_name=models.CharField(max_length=30)
    product_count=models.PositiveIntegerField()
    product_cost=models.PositiveIntegerField()
    seller_name=models.ForeignKey('auth.User',on_delete=models.CASCADE)
    product_img=models.ImageField(blank=True,null=True,upload_to='product_img')

    def get_absolute_url(self):
        return reverse("home")
    def __str__(self):
        return self.product_name

class Transaction(models.Model):
    buyer_name=models.ForeignKey('auth.User',on_delete=models.CASCADE,related_name='transactions')
    purchase_date=models.DateTimeField(default=timezone.now,null=True)
    products=models.ManyToManyField('Product',related_name='producttxn',blank=True)
    amount = models.IntegerField()
    order_id = models.CharField(unique=True, max_length=100, null=True, blank=True)
    checksum = models.CharField(max_length=100, null=True, blank=True)

    def save(self, *args, **kwargs):
        if self.order_id is None and self.purchase_date and self.id:
            self.order_id = self.purchase_date.strftime('PAY2ME%Y%m%dODR') + str(self.id)
        return super().save(*args, **kwargs)

    def get_absolute_url(self):
        return reverse("home")

    def __str__(self):
        return str(self.buyer_name)

# class Cart(models.Model):
#     buyer_name=models.ForeignKey('auth.User',on_delete=models.CASCADE,related_name='transactions')
#     purchase_date=models.DateTimeField(default=timezone.now,null=True)
#     products=models.ManyToManyField('Product',blank=True)
#
#     def get_absolute_url(self):
#         return reverse("home")
#
#     def __str__(self):
#         return str(self.buyer_name)
