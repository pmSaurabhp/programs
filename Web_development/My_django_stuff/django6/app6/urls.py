
from django.urls import path,include
from app6 import views

app_name='app6'
urlpatterns = [
    path('register/',views.register,name='register'),
    path('login/',views.user_login,name='user_login'),
]
