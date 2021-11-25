from django.shortcuts import render

# Create your views here.
from django.views.generic import CreateView,TemplateView,UpdateView,DetailView,ListView
from django.shortcuts import render, get_object_or_404, redirect
from django.contrib.auth.decorators import login_required
from django.contrib.auth.mixins import LoginRequiredMixin
from inventory.models import Product,Transaction
from inventory.forms import CartForm
from django.contrib.auth.models import User

from django.contrib.auth import authenticate, login as auth_login
from django.conf import settings
from .paytm import generate_checksum, verify_checksum

class HomeView(TemplateView):
    template_name='home.html'
    context_object_name='object'

class ListProduct(ListView):
    model=Product
    template_name='product_list.html'
    context_object_name='object'

class AddProduct(LoginRequiredMixin,CreateView):
    login_url='login/'
    model=Product
    template_name='product_form.html'
    context_object_name='object'
    fields=('product_name','product_cost','product_count','product_img')

    def form_valid(self,form):                  # auther field is automaticaly assigned as user who is logged in
        form.instance.seller_name=self.request.user
        return super().form_valid(form)

class DetailProduct(DetailView):
    model=Product
    template_name='product_detail.html'
    context_object_name='object'
    fields='__all__'

class ListCart(ListView):
    # model not there
    template_name='cart_list.html'
    context_object_name='object'
            # get_queryset() has self as argument
           # instead of model = Transaction
           # we used get_queryset(self) because we want dynamic filtering
    def get_queryset(self):
        name=get_object_or_404(User,username=self.request.user.username)
        return Transaction.objects.filter(buyer_name=name)

class DetailCart(DetailView):
    model=Transaction
    template_name='cart_detail.html'
    context_object_name='object'
    fields='__all__'


@login_required
def initiate_payment(request,pk):
 if request.method == "GET":

     product = get_object_or_404(Product,pk=pk)
     user=User.objects.get(username=request.user.username)

     txn=product.producttxn.create(buyer_name=user, amount=product.product_cost)
     txn.save()
     product.save()



     merchant_key = settings.PAYTM_SECRET_KEY
     params = (
         ('MID', settings.PAYTM_MERCHANT_ID),
         ('ORDER_ID', str(txn.order_id)),
         ('CUST_ID', str(txn.buyer_name.email)),
         ('TXN_AMOUNT', str(txn.amount)),
         ('CHANNEL_ID', settings.PAYTM_CHANNEL_ID),
         ('WEBSITE', settings.PAYTM_WEBSITE),
         # ('EMAIL', request.user.email),
         # ('MOBILE_N0', '9911223388'),
         ('INDUSTRY_TYPE_ID', settings.PAYTM_INDUSTRY_TYPE_ID),
         ('CALLBACK_URL', 'http://localhost:8000/callback/'),
         # ('PAYMENT_MODE_ONLY', 'NO'),
     )

     paytm_params = dict(params)
     checksum = generate_checksum(paytm_params, merchant_key)
     txn.checksum = checksum
     txn.save()


     paytm_params['CHECKSUMHASH'] = checksum
     print('SENT: ', checksum)
     return render(request, 'redirect.html', context=paytm_params)


from django.views.decorators.csrf import csrf_exempt

@csrf_exempt
def callback(request):
    if request.method == 'POST':
        received_data = dict(request.POST)
        paytm_params = {}
        paytm_checksum = received_data['CHECKSUMHASH'][0]
        for key, value in received_data.items():
            if key == 'CHECKSUMHASH':
                paytm_checksum = value[0]
            else:
                paytm_params[key] = str(value[0])
        # Verify checksum
        is_valid_checksum = verify_checksum(paytm_params, settings.PAYTM_SECRET_KEY, str(paytm_checksum))
        if is_valid_checksum:
            received_data['message'] = "Checksum Matched"
        else:
            received_data['message'] = "Checksum Mismatched"

        txn_status=received_data['STATUS'][0]
        txn_orderid=received_data['ORDERID'][0]
        if txn_status=='TXN_SUCCESS':
            txn=Transaction.objects.get(order_id=txn_orderid)
            for i in txn.products.all():
                i.product_count=i.product_count-1
                i.save()
            txn.save()

        return render(request, 'callback.html', context=received_data)




# class ListCart(ListView):
#     # model not there
#     template_name='cart_list.html'
#     context_object_name='object'
#                                     # get_queryset() has self as argument
#     def get_queryset(self):         # instead of model = Cart we used get_queryset(self) because we want dynamic filtering
#         name=get_object_or_404(User,username=self.request.user.username)
#         return Cart.objects.filter(buyer_name=name)
#
# class DetailCart(DetailView):
#     model=Cart
#     template_name='cart_detail.html'
#     context_object_name='object'
#     fields='__all__'
#
#
# @login_required
# def add_buyer_to_product(request,pk):
#
#     product = get_object_or_404(Product,pk=pk)
#
#     if request.method == "GET":
#
#         product.product_count=product.product_count-1
#
#         name=User.objects.get(username=request.user.username)
#         product.cart_set.create(buyer_name=name)
#         product.save()
#         return redirect('home')
