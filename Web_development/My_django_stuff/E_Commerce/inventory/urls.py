from django.urls import path
from inventory import views

urlpatterns = [
    path('',views.HomeView.as_view(),name='home'),
    path('list/',views.ListProduct.as_view(),name='list'),
    path('product/',views.AddProduct.as_view(),name='add'),
    path('detail/<int:pk>',views.DetailProduct.as_view(),name='detail'),

    path('pay/<int:pk>', views.initiate_payment, name='pay'),
    path('callback/', views.callback, name='callback'),

    path('cart/<int:pk>',views.DetailCart.as_view(),name='cartdetail'),
    path('cartlist/',views.ListCart.as_view(),name='cartlist'),
]
