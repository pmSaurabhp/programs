from django.urls import path
from app1 import views

app_name='sksfsas'
urlpatterns = [
    path('list/',views.SchoolListView.as_view(),name='list'),
    path('list/<int:pk>/',views.SchoolDetailView.as_view(),name="detail"),
    path('create/',views.SchoolCreateView.as_view(),name='create'),
    path('list/update/<int:pk>/',views.SchoolUpdateView.as_view(),name="update"),
    path('list/delete/<int:pk>/',views.SchoolDeleteView.as_view(),name="delete"),
]
