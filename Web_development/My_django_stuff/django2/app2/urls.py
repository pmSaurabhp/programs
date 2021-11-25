from django.urls import path
from django.conf.urls import include
from app2 import views

urlpatterns = [
    path('',views.index,name='index'),

]
