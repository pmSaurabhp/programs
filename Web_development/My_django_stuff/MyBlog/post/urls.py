from django.urls import path
from post import views


urlpatterns = [
    path('',views.Home.as_view(),name='home'),
    path('detail/<int:pk>/',views.PostDetail.as_view(),name='detail'),
    path('create/',views.PostCreate.as_view(),name='create'),
    path('update/<int:pk>/',views.PostUpdate.as_view(),name='update'),
    path('delete/<int:pk>/',views.PostDelete.as_view(),name='delete'),

]
