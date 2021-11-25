from django.urls import path
from users.views import SignUpView,HomeView

urlpatterns=[
path('',HomeView.as_view(),name='home'),
path('signup/',SignUpView.as_view(),name='signup'),

]
