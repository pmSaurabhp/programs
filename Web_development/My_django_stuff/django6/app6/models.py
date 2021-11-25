from django.db import models

# Create your models here.
from django.contrib.auth.models import User

class UserProfile(models.Model):
    # custom user model
    user=models.OneToOneField(User,on_delete=models.CASCADE)
    # User fields eg username,email,password will also be inherited in onetoone fashion

    portfolio_site=models.URLField(blank=True)
    profile_pic=models.ImageField(blank=True,upload_to='profile_pics')

    def __str__(self):
        return self.user.username
