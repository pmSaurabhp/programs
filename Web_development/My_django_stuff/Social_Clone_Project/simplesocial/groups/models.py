from django.db import models
from django.conf import settings
from django.urls import reverse
from django.utils.text import slugify
# from accounts.models import User

# pip install misaka
import misaka   # used for giving links in textfield

from django.contrib.auth import get_user_model
User = get_user_model()

# https://docs.djangoproject.com/en/2.0/howto/custom-template-tags/#inclusion-tags
# This is for the in_group_members check template tag
from django import template
register = template.Library()

class Group(models.Model):
    name = models.CharField(max_length=255, unique=True)
    slug = models.SlugField(allow_unicode=True, unique=True)
         #Slug is a part of a URL which identifies a particular page on a website in a form readable by users.
            # slugify changes FirstGroup -> firstgroup and is added tu url
    # http://127.0.0.1:8000/groups/posts/in/firstgroup/
    description = models.TextField(blank=True, default='')
    description_html = models.TextField(editable=False, default='', blank=True)
    members = models.ManyToManyField(User,through="GroupMember")  # used instead of foreignKey
                                    # used because a group can have many person and a person can have many groups
                                    #  https://www.revsys.com/tidbits/tips-using-djangos-manytomanyfield/
    def __str__(self):
        return self.name

    def save(self, *args, **kwargs):
        self.slug = slugify(self.name)
        self.description_html = misaka.html(self.description)
        super().save(*args, **kwargs)

    def get_absolute_url(self):
        return reverse("groups:single", kwargs={"slug": self.slug})


    class Meta:
        ordering = ["name"]

#----------------------
                                                    #
class GroupMember(models.Model):                    #
    group = models.ForeignKey(Group,related_name='memberships',on_delete=models.CASCADE)
    user = models.ForeignKey(User,related_name='user_groups',on_delete=models.CASCADE)
                                            # use get_user_groups in post_list.html
    def __str__(self):
        return self.user.username

    class Meta:
        unique_together = ("group", "user")
