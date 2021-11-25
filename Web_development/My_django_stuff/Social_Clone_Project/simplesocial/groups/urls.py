from django.urls import path
from . import views

app_name = 'groups'

urlpatterns = [
    path('', views.ListGroups.as_view(), name="all"),
    path("new/", views.CreateGroup.as_view(), name="create"),
    path("posts/in/<slug>/",views.SingleGroup.as_view(),name="single"), #slug used instead of pk as slugs are more readable
    path("join/<slug>/",views.JoinGroup.as_view(),name="join"),
    path("leave/<slug>/",views.LeaveGroup.as_view(),name="leave"),
]
#Slug is a part of a URL which identifies a particular page on a website in a form readable by users.
# slugify changes First Group -> first_group and is added tu url
# http://127.0.0.1:8000/groups/posts/in/firstgroup/
