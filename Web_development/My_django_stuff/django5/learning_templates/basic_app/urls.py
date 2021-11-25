
from django.urls import path
from basic_app import views

app_name='basic_app'           # app_name keyword

urlpatterns = [
    path('relative/',views.relative,name='relative'),    #  basic_app.relative = learning_templates\templates\basic_app\relative.py
    path('other/',views.other,name='other'),
]
