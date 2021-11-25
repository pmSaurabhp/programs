from django.shortcuts import render
from post.models import Post
from django.views.generic import (ListView,DetailView,CreateView,UpdateView,DeleteView)
from django.urls import reverse_lazy
from django.contrib.auth.mixins import LoginRequiredMixin,UserPassesTestMixin
# Create your views here.
class Home(ListView):
    model=Post
    template_name='post_list.html'
    context_object_name='object'

class PostDetail(DetailView):
    model=Post
    template_name='post\post_detail.html'
    context_object_name='detail_o'

class PostCreate(LoginRequiredMixin,CreateView):
    login_url='login'
    model=Post
    template_name="post\post_form.html"
    fields=('title','text')

    def form_valid(self,form):                  # auther field is automaticaly assigned as user who is logged in
        form.instance.author=self.request.user
        return super().form_valid(form)

class PostUpdate(LoginRequiredMixin,UserPassesTestMixin,UpdateView):
    login_url='login'
    model=Post
    template_name='post\post_form.html'
    fields={'title','text'}

    def test_func(self):                    # the user logged in can update only his post not other users post
        obj=self.get_object()
        return obj.author == self.request.user

class PostDelete(LoginRequiredMixin,UserPassesTestMixin,DeleteView):
    login_url='login'
    model=Post
    template_name='post\post_delete.html'
    success_url=reverse_lazy('home')

    def test_func(self):
        obj=self.get_object()
        return obj.author == self.request.user
